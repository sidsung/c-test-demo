#include "stdio.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "stdint.h"

typedef struct
{
    uint32_t byte1;
} power_s;

int get_power(power_s *power_buf)
{
    power_buf->byte1 = 255;
    return 0;
}

void get_k(int *k)
{
    *k = 1222;
}

float fun(int power)
{
    char a[20];
    float b;
    int integer = 0, decimals = 0;
    integer = power / 1000;
    decimals = power % 1000;

    if (decimals >= 100)
        sprintf(a, "%d.%d", integer, decimals); //拼接成字符串
    else if (decimals < 100 && decimals >= 10)
        sprintf(a, "%d.0%d", integer, decimals); //拼接成字符串
    else if (decimals >= 0 && decimals < 10)
        sprintf(a, "%d.00%d", integer, decimals); //拼接成字符串

    sscanf(a, "%f", &b); //转换成数字 字符转数字函数
    printf("%.3f\n", b); //精确到小数点后两位

    return b;
}

int main()
{
    // power_s buf;
    // get_power(&buf);

    // printf("byte1 = %d\n", buf.byte1);

    int k = 1000;
    float power = fun(k);
    printf("power = %.3f\n", power); //精确到小数点后两位
}