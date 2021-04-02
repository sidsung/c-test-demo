#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"

#define pro_log_debug(info...) \
    {                          \
        printf(info);          \
        printf("\n");          \
    };

typedef int32_t esp_err_t;
#define FUN_BLE_BUF_SIZE 1024
#define ESP_OK 0
#define ESP_FAIL -1
#define APP_CONF_HTTP_FIRMWARE "1.2.0.94"
#define INFO_LIST_FIRMWARE_VER 5
#define INFO_LIST_WIFI_RSSI 8

int pro_ble_send_data(int version, int command, uint8_t *data, int data_len, uint8_t *out, int out_len)
{
    if ((data == NULL) || (out == NULL) || (out_len <= 16) || (data_len >= out_len - 16))
    {
        pro_log_debug("%s:param NULL!", __func__);
        return ESP_FAIL;
    }

    int len = 0;
    out[len++] = 'H';
    out[len++] = 'L';
    out[len++] = version % 256;
    out[len++] = version / 256;
    out[len++] = command % 256;
    out[len++] = command / 256;
    out[len++] = data_len % 256;
    out[len++] = data_len / 256;
    for (int i = 0; i < 8; i++)
    {
        out[len++] = 0;
    }
    memcpy(out + len, data, data_len);
    len += data_len;

    if (len < out_len)
    {
        return len;
    }
    pro_log_debug("%s:insufficient array length!", __func__);
    return ESP_FAIL;
}

/**
 * @brief 解析 获取设备信息 指令
 */
esp_err_t pro_ble_prase_info_list(uint8_t *data, int data_len, uint8_t *infoNum, uint8_t infoIdList[])
{
    if (NULL == data || data_len < 0)
    {
        pro_log_debug("params error");
        return ESP_FAIL;
    }
    pro_log_debug("recive data[%s]", data);

    /* 要获取的设备属性的个数 */
    *infoNum = data[0];

    /* 具体的设备属性ID */
    int i;
    for (i = 0; i < *infoNum; i++)
    {
        infoIdList[i] = data[i + 1];
    }

    return ESP_OK;
}

/**
 * @brief 根据APP下发的熟悉ID返回相应设备属性信息
 */
int pro_ble_send_info_list(uint8_t infoNum, uint8_t infoIdList[], uint8_t *out, int out_len)
{
    if (NULL == infoIdList || infoNum < 0)
    {
        pro_log_debug("params error");
        return ESP_FAIL;
    }

    int data_len = 15;
    uint8_t data[data_len];

    /* 返回的设备属性个数 */
    uint8_t sendInfoNum = 0;
    /* 第一个字节为返回的设备属性个数 */
    int len = 1;

    int i;
    for (i = 0; i < infoNum; i++)
    {
        switch (infoIdList[i])
        {
        case INFO_LIST_FIRMWARE_VER:
        {
            sendInfoNum++;
            data[len++] = INFO_LIST_FIRMWARE_VER;
            data[len++] = strlen(APP_CONF_HTTP_FIRMWARE);
            len += snprintf((char *)data + len, data_len - len, "%s", APP_CONF_HTTP_FIRMWARE);
        }
        break;
        case INFO_LIST_WIFI_RSSI:
        {
            sendInfoNum++;
            data[len++] = INFO_LIST_WIFI_RSSI;
            data[len++] = 1;
            data[len++] = -35;
        }
        break;
        default:
            break;
        }
    }
    data[0] = sendInfoNum;
    pro_log_debug("sendInfoList[%s]", data);

    for (i = 0; i < data_len; i++)
    {
        pro_log_debug("sendInfoList[%d][%d]", i, data[i]);
    }

    return pro_ble_send_data(1, 1025, data, data_len, out, out_len);
}

int main()
{
    uint8_t paramData[] = {2, 5, 8};

    uint8_t infoNum = 0;
    uint8_t infoIdList[] = "";

    esp_err_t ret = pro_ble_prase_info_list(paramData, sizeof(paramData), &infoNum, infoIdList);

    if (ESP_OK != ret)
    {
        pro_log_debug("prase info list error");
        return 0;
    }
    pro_log_debug("info num[%d]", infoNum);

    int i;
    for (i = 0; i < infoNum; i++)
    {
        pro_log_debug("info[%d][%d]", i, infoIdList[i]);
    }

    uint8_t buf[FUN_BLE_BUF_SIZE];
    int buf_len = pro_ble_send_info_list(infoNum, infoIdList, buf, FUN_BLE_BUF_SIZE);

    if (buf_len <= 0)
    {
        pro_log_debug("buf len error");
        return 0;
    }

    pro_log_debug("buf[%s]", buf);
    for (i = 0; i < buf_len; i++)
    {
        pro_log_debug("buf[%d][%d]", i, buf[i]);
    }

    return 0;
}