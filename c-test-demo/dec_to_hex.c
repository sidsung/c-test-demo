#include "stdio.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "stdint.h"

#define ESP_OK 1
#define ESP_FAIL 0

int check_sum_cmp(int uart_check_sum, int check_sum_temp)
{
    char buf[10] = {0};
    sprintf(buf, "%x", uart_check_sum);

    printf("%s\n", buf);

    char hex_check[2] = {0};
    memcpy(hex_check, buf + (strlen(buf) - 2), strlen(buf));

    printf("%s\n", hex_check);

    char check_sum_buf[2] = {0};
    sprintf(check_sum_buf, "%x", check_sum_temp);

    printf("%s\n", check_sum_buf);

    if (!strncmp(hex_check, check_sum_buf, 2))
        return ESP_OK;
    else
        return ESP_FAIL;
}

int send_check_sum(int dec_sum)
{
    char buf[10] = {0};
    sprintf(buf, "%x", dec_sum);
    char hex_check[2] = {0};
    memcpy(hex_check, buf + (strlen(buf) - 2), strlen(buf));

    printf("%s\n", hex_check);

    char data_buf[10] = {0XFE, 0X01, 0X23, 0X02};
    int data_len = 4;
    memcpy(data_buf + data_len, hex_check, 2);
    printf("%s\n", data_buf);
    return 0;
}

int change(char *str)
{
    int result = 0;
    int flag = 0;

    if (*str == '-')
    {
        flag = 1;
        str++;
    }

    while (*str)
    {
        if (*str >= '0' && *str <= '9')
            result = result * 16 + (*str - '0');
        else if (*str >= 'a' && *str <= 'f')
            result = result * 16 + (*str - 'a' + 10);
        else if (*str >= 'A' && *str <= 'F')
            result = result * 16 + (*str - 'A' + 10);
        str++;
    }

    if (flag == 1)
        result = -result;
    return result;
}

int main()
{
    // int dec = 279;
    // int check_sum = 23;

    // int a = check_sum_cmp(dec, check_sum);
    // int b = 0x117;
    // b %= 100;
    // printf("%x\n", b);

    // send_check_sum(279);

    // char FWV[20] = {'1', '.', '0', '.', '0', '2', '3', '9', '1'};
    char FWM[20] = {'W', 'L', 'P', 'P', 'O'};
    // char hex[10] = {'1', 'A'};
    // int sum = atoi(hex);
    // printf("%d\n", sum);

    // char str[] = "1A";
    // int res = change(str);
    // printf("%X\n", res);

    char noMac[] = {'0', '8', '0', '8', '0', '8', '0', '8', '0', '8', '0', '8', '0', '8', '0', '8', '0', '8', '0', '8', '0', '8', '0', '8'};

    printf("%ld\n", strlen(noMac));
}
