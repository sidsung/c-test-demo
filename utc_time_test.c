#include "stdio.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "stdint.h"

typedef struct
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int week;
} UTCTime_s;

void get_utc_time(UTCTime_s *utc_time)
{
    char year_buf[10] = {0};
    char month_buf[10] = {0};
    char day_buf[10] = {0};
    char hour_buf[10] = {0};
    char minute_buf[10] = {0};

    time_t utc_tim;
    time(&utc_tim);
    struct tm *p_time = gmtime(&utc_tim);
    // strftime(year_buf, sizeof(year_buf), "%Y%m%d%H", p_time);
    strftime(year_buf, sizeof(year_buf), "%Y", p_time);
    utc_time->year = atoi(year_buf);

    strftime(month_buf, sizeof(month_buf), "%m", p_time);
    utc_time->month = atoi(month_buf);

    strftime(day_buf, sizeof(day_buf), "%d", p_time);
    utc_time->day = atoi(day_buf);

    strftime(hour_buf, sizeof(hour_buf), "%H", p_time);
    utc_time->hour = atoi(hour_buf);

    strftime(minute_buf, sizeof(minute_buf), "%M", p_time);
    utc_time->minute = atoi(minute_buf);

    utc_time->week = p_time->tm_wday;
}

typedef struct
{
    int power_use_hour[13][32][24]; // 某月某日 每小时用电量
    int power_use_day[13][32];      // 某月 每日用电量
    int power_use_month[13];        // 每月用电量
} power_use_s;                      // 电量计量

static power_use_s power_use = {
    .power_use_hour = {{{0}}},
    .power_use_day = {{0}},
    .power_use_month = {0},
};

UTCTime_s utc_time;
char *lastDate = "2020-9-1";

int pub(int powerUse[24], char *reportDate)
{
    int data_addr = 0, i = 0;
    char data[512];
    for (i = 0; i < 24; i++)
    {
        data_addr += sprintf(data + data_addr, "%d", powerUse[i]);
        if (i < 24 - 1)
            data_addr += sprintf(data + data_addr, ",");
    }

    printf("%s\n", data);
    printf("%s\n", reportDate);
    return 0;
}

int main()
{
    get_utc_time(&utc_time);

    // printf("%d\n", utc_time.year);
    // printf("%d\n", utc_time.month);
    // printf("%d\n", utc_time.day);
    // printf("%d\n", utc_time.hour);
    // printf("%d\n", utc_time.minute);
    // printf("week %d\n", utc_time.week);

    // power_use.power_use_hour[utc_time.month][utc_time.day][utc_time.hour] = 50;
    // int power[24] = {0};
    // //  power_use.power_use_hour[utc_time.month][utc_time.day];
    // memset(&power_use, 0, sizeof(power_use_s));
    // memcpy(power, power_use.power_use_hour[utc_time.month][utc_time.day], sizeof(power));

    // for (int i = 0; i < 24; i++)
    // {
    //     printf("%d\n", power[i]);
    // }

    // int a[24] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,0,0,0,0,0,0,0,0,0};
    int a[24] = {0};

    // pub(a, lastDate);
    int b = 123456789;
    printf("%d\n", (uint16_t)b);

    return 0;
}