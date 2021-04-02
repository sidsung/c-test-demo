#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "time.h"
#include "string.h"

int esp_wifi_restore()
{
    return 1;
}

void test1()
{
    int err = -1;
    uint8_t retryTime = 0;

    do
    {
        err = esp_wifi_restore();

        if (0 != err)
        {
            retryTime++;
            printf("resore wifi info fail, retry\n");
        }

        if (retryTime >= 3)
            break;
    } while (err);
}

int main()
{
    // int excute = 0;
    // int ret = 0;
    // do
    // {
    //     excute++;
    //     printf("excuted times: %d\n", excute);
    // } while (ret != 0);

    test1();
}