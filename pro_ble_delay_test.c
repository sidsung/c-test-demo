#include <stdio.h>
#include <string.h>
typedef struct
{
    int submac_len; //The lenth of mac adders
    int operate_len;
    int delay_time_len; //The lenth of delay time
    int submac_flag;
    int operate_flag;
    int delay_time_flag;
    char submac[20];
    int operate;
    int delay_time;
} pro_ble_delay_set_s; //Delay time control task

int pro_ble_dir_delay_conl(char *data, int data_len, pro_ble_delay_set_s *out)
{
    int len = 0;

    out->submac_len = data[0];

    int operate_len = 1;
    int submac_len = data[0];

    len = submac_len + operate_len + 1; // 加上submac_len自身长度1

    printf("len %d\n", len);

    int delay_time_len = data[len];
    printf("delay_time_len %d\n", delay_time_len);

    len += delay_time_len + 1; // 加上delay_time_len自身长度1

    if (len != data_len)
    {
        printf("data length error! the lenth is %d\n", len);
    }

    out->submac_flag = 0;
    out->operate_flag = 0;
    out->delay_time_flag = 0;

    len -= delay_time_len;
    printf("len now =  %d\n", len);
    if (delay_time_len > 0)
    {
        out->delay_time_flag = 1;

        int a = 0;
        int b = 0;
        for (int i = 0; i < delay_time_len; i++)
        {
            b = (int)data[i + 20] - 48;
            a = (a * 10) + b;
            printf("a =  %d\n", a);
        }

        out->delay_time = a;
        printf("delay time %d\n", out->delay_time);
    }

    len -= operate_len + 1;
    if ((operate_len > 0) && (operate_len < sizeof(out->operate)))
    {
        out->operate_flag = 1;
        out->operate = data[len];
        printf("operate %d\n", out->operate);
    }
    else if (operate_len == 0)
    {
        out->operate_flag = 2;
    }

    len -= submac_len;
    if (submac_len > 0 && submac_len < sizeof(out->submac))
    {
        out->submac_flag = 1;
        memcpy(out->submac, data + len, submac_len);
        printf("submac : %s\n", out->submac);
    }
}

unsigned char data[1024] = {17, 'e', '4', 'a', 'a', 'e', 'c', '1', 'f', 'b', '7', '5', 'a', '-', '0', '0', '0', '1', 0, 5, '8', '2', '8', '2', '9'};
int data_len = 25;

int main()
{
    // sprintf((data + 20), "%d", 82820);
    pro_ble_delay_set_s conl = {};
    pro_ble_dir_delay_conl(data, data_len, &conl);

    printf("submac_len = %d\n", data[0]);

    char submac[20];
    memcpy(submac, data + 1, sizeof(submac));
    printf("submac %s\n", submac);

    printf("operate = %d\n", data[18]);

    printf("delay_time_len = %d\n", data[19]);

    // for (int i = 0; i < 30; i++)
    // {
    //     printf("delay time %d\n", data[i]);
    // }

    // char a = data[20];
    // a -= 48;
    // a *= 10;
    // printf("delay time %d\n", a);

    // printf("delay time %s\n", data + 20);
    
    // int delay_time[10];
    // memcpy(delay_time, data + 20, 5);
    // delay_time[6] = '\0';

    // int delay_time = data[20] << 8;
    // delay_time |= data[19];
    // printf("delay time %d\n",delay_time);
}