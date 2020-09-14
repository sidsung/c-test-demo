#include "stdio.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "stdint.h"

typedef struct week_test
{
    int year;
    int month;
    int day;
} localtime_s;

/**
 * @brief 获取当前时间 月、日、时、分
 */
uint32_t get_local_time(localtime_s *local_date)
{
    time_t tim;
    char ctime_buf_y[20] = "";
    char ctime_buf_m[20] = "";
    char ctime_buf_d[20] = "";

    time(&tim);
    // strftime(ctime_buf, 20, "%Y%m%d", localtime(&tim));
    strftime(ctime_buf_y, 20, "%Y", localtime(&tim));
    local_date->year = atoi(ctime_buf_y);

    strftime(ctime_buf_m, 20, "%m", localtime(&tim));
    local_date->month = atoi(ctime_buf_m);

    strftime(ctime_buf_d, 20, "%d", localtime(&tim));
    local_date->day = atoi(ctime_buf_d);

    printf("%d - %d - %d\n", local_date->year, local_date->month, local_date->day);

    return 0;
}

typedef struct
{
    int power_use_hour[13][32][24]; // 某年某月某日 每小时用电量
    int power_use_day[13][32];      // 某年某月 每日用电量
    int power_use_month[13];        // 某年 每月用电量
} power_use_s;                      // 电量计量

power_use_s power_use = {
    .power_use_hour = {0},
    .power_use_day = {0},
    .power_use_month = {0},
};

localtime_s local_date;

int get_all_power_use(power_use_s *power_use)
{
    get_local_time(&local_date);
    printf("%d-%d-%d\n", local_date.year, local_date.month, local_date.day);

    power_use->power_use_day[local_date.month][local_date.day] = 50;
    power_use->power_use_day[local_date.month][6] = 50;
    power_use->power_use_hour[9][7][23] = 11;

    for (int i = 0; i < 24; i++)
    {
        power_use->power_use_day[local_date.month][local_date.day] +=
            power_use->power_use_hour[local_date.month][local_date.day][i];
    }

    for (int i = 0; i < 32; i++)
    {
        power_use->power_use_month[local_date.month] += power_use->power_use_day[local_date.month][i];
    }

    printf("%d-%d's all power use is %d\n", local_date.year, local_date.month, power_use->power_use_month[local_date.month]);

    return 0;
}

int main()
{
    // get_all_power_use(&power_use);

    // printf("this month's all power use is %d\n", power_use.power_use_month[local_date.month]);

    int p[32][24] = {0};

    memset(&power_use.power_use_hour[1], 0, sizeof(power_use.power_use_hour[1]));

    printf("%ld\n", sizeof(power_use.power_use_hour[1]));

    for (int i = 0; i < 24; i++)
    {
        printf("%d\n", power_use.power_use_hour[1][1][i]);
    }

    return 0;
}