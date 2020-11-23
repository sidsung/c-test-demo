#include <stdio.h>
#include <string.h>

int submac_len = 17;
char submacc[20] = {'e', '4', 'a', 'a','e', 'c', '1', 'f', 'b', '7', '5', 'a', '-', '0', '0', '0','1'};
char submac[20] = {"e4aaec1fb75a-0001"};
// int submac[20] = {0};
int command = 0x0B;
int result = 1;

int main()
{
    char buf[30] = {0};
    int len = 0;

    buf[len++] = submac_len;
    // memcpy(buf, submac_len, sizeof(submac_len));
    memcpy((buf + len), submac, sizeof(submac));
    len = len + submac_len;
    buf[len++] = command;
    buf[len++] = 0;
    // len += 1;
    buf[len++] = result;
    buf[len] = '\0';

    printf("the results are :");
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", buf[i]);
    }
    printf("the len is %d\n", len);

    return 0;
}