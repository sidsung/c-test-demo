#include "stdio.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "stdint.h"

int main()
{
    int test[4] = {0X2E, 0XE0};
    int vol_12v = 0; // 12 * 1000
    vol_12v = ((test[0] & 0xffff) << 8) | test[1];
    printf("vol_12v = %X\n", vol_12v);

    int vol_1, vol_2 = 0;
    vol_2 = vol_12v & 0xff;
    vol_1 = vol_12v >> 8;
    printf("vol_1 = %X\n", vol_1);
    printf("vol_2 = %X\n", vol_2);
    return 0;
}