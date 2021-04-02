#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

int main()
{
    uint8_t oneByte = -1;
    int8_t oneByteTow = -128;
    uint8_t *data = malloc(2);
    data[0] = -35;

    printf("onebyte[%d]\n", data[0]);
}