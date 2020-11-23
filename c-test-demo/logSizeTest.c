#include "stdio.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "stdint.h"

// 4字节最大表示 4,294,967,295

int logSizeTest()
{
    size_t allLogSize = 0;
    printf("allLogSize = %ld\n", allLogSize);
    long fourByte = 49169;
    printf("fourByte = %ld\n", fourByte);

    int len = 0;
    char buf[2] = {0};
    buf[len++] = fourByte % 256;
    buf[len++] = fourByte / 256;
    printf("1 = %d\n2 = %d\n", buf[0], buf[1]);

    //大端模式
    int byteOne = 0, byteTwo = 0, byteThree = 0, byteFour = 0;

    byteOne = (fourByte >> 24) & 0xff;
    printf("byteOne = %d\n", byteOne);

    byteTwo = (fourByte >> 16) & 0xff;
    printf("byteTwo = %d\n", byteTwo);

    byteThree = (fourByte >> 8) & 0xff;
    printf("byteThree = %d\n", byteThree);

    byteFour = fourByte & 0xff;
    printf("byteFour = %d\n", byteFour);

    return 0;
}

int main()
{
    logSizeTest();
    return 0;
}