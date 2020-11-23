#include "stdio.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "stdint.h"

#define FW_VER "1.2.0.6"

#define TEST 1 //服务器
#define BETA 2
#define OFFICIAL 3

int CHOOSE_SERVER;

int func()
{
    int len = strlen(FW_VER);
    printf("the len of fw ver : [%d]\n", len);

    int lastNum = atoi(&FW_VER[len - 1]);
    printf("the len of fw ver : [%d]\n", lastNum);

    if (1 == lastNum || 4 == lastNum || 7 == lastNum)
        CHOOSE_SERVER = TEST;
    else if (2 == lastNum || 5 == lastNum || 8 == lastNum)
        CHOOSE_SERVER = BETA;
    else if (3 == lastNum || 6 == lastNum || 9 == lastNum)
        CHOOSE_SERVER = OFFICIAL;

    printf("CHOOSE_SERVER = [%d]\n", CHOOSE_SERVER);
    return 0;
}

int main()
{
    func();
    return 0;
}