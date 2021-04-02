#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
// #include </home/sidsung/esp/idftest/HomeKitTest/esp-homekit-sdk/components/homekit/esp_hap_core/include/hap.h>
#include </home/sidsung/esp/idftest/HomeKitTest/esp-homekit-sdk/components/homekit/esp_hap_core/src/priv_includes/base36.h>

#include "qrcode.h"

#define SETUP_CODE_MASK 0x0000000007ffffff
#define HAP_OVER_IP_MASK 0x0000000010000000
#define WAC_MASK 0x0000000040000000
#define SETUP_PAYLOAD_PREFIX "X-HM://00"

#define QRCODE_BASE_URL "https://espressif.github.io/esp-homekit-sdk/qrcode.html"

static void remove_chars(char *str, char c)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != c)
        {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = 0;
}

char *esp_hap_get_setup_payload(char *setup_code, char *setup_id, bool wac_support, uint8_t cid)
{
    if (!setup_code || !setup_id)
    {
        printf("Setup code or Setup ID cannot be NULL\n");
        return NULL;
    }
    uint64_t payload = 0;
    if (strlen(setup_code) != 10 || strlen(setup_id) != 4)
    {
        printf("Setup code or Setup ID not correct. Eg. 111-22-333, ES32\n");
        return NULL;
    }
    char setup_code_copy[11];
    strcpy(setup_code_copy, setup_code);
    remove_chars(setup_code_copy, '-');
    int64_t code = atoi(setup_code_copy);
    int64_t category = cid;
    category <<= 31;

    payload |= code;
    payload |= category;
    payload |= HAP_OVER_IP_MASK;
    if (wac_support)
    {
        payload |= WAC_MASK;
    }
    char *base36_str = base36_to_str(payload);
    char setup_payload[24];
    snprintf(setup_payload, sizeof(setup_payload), "%s%s%s", SETUP_PAYLOAD_PREFIX, base36_str, setup_id);
    free(base36_str);
    return strdup(setup_payload);
}

int main()
{
    char *setup_code = "199-70-712";
    char *setup_id = "yanx";
    bool wac_support = false;
    uint8_t cid = 7;

    char *setup_payload = esp_hap_get_setup_payload(setup_code, setup_id, wac_support, cid);
    printf("%s\n", setup_payload);
    // qrcode_display(setup_payload);
    printf("If QR code is not visible, copy paste the below URL in a browser.\n%s?data=%s\n", QRCODE_BASE_URL, setup_payload);
    free(setup_payload);
}