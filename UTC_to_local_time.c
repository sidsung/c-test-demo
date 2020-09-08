#include "stdio.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "stdint.h"

// int get_time(void)
// {
//     time_t tim;
//     char ctime_buf[10] = "";

//     time(&tim);
//     strftime(ctime_buf, 10, "%H%M", localtime(&tim));
//     int utc_time = atoi(ctime_buf);
//     return utc_time;
// }

//UTC转换为北京时间  函数可直接调用
void UTCToBeijing(unsigned int UTCyear, unsigned char UTCmonth, unsigned char UTCday, unsigned int UTChour, unsigned char UTCminute, unsigned char UTCsecond)
{
    int year = 0, month = 0, day = 0, hour = 0;
    int lastday = 0;     // 月的最后一天日期
    int lastlastday = 0; //上月的最后一天日期

    year = UTCyear;
    month = UTCmonth;
    day = UTCday;
    hour = UTChour + 8; //UTC+8转换为北京时间

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        lastday = 31;
        if (month == 3)
        {
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) //判断是否为闰年
                lastlastday = 29;                                        //闰年的2月为29天，平年为28天
            else
                lastlastday = 28;
        }
        if (month == 8)
            lastlastday = 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        lastday = 30;
        lastlastday = 31;
    }
    else
    {
        lastlastday = 31;
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) //闰年的2月为29天，平年为28天
            lastday = 29;
        else
            lastday = 28;
    }
    if (hour >= 24) //当算出的时大于或等于24：00时，应减去24：00，日期加一天
    {
        hour -= 24;
        day += 1;
        if (day > lastday) //当算出的日期大于该月最后一天时，应减去该月最后一天的日期，月份加上一个月
        {
            day -= lastday;
            month += 1;

            if (month > 12) //当算出的月份大于12，应减去12，年份加上1年
            {
                month -= 12;
                year += 1;
            }
        }
    }
    printf("year : %d\n", year);
    printf("month : %d\n", month);
    printf("day : %d\n", day);
    printf("hour : %d\n", hour);
}

/*
BJT->UTC
*/
int BJT_to_UTC(void)
{
    int BJT, UTC;
    int hour;
    int minute;
    int u_hour, u_minute;
    scanf("%d", &BJT);
    if (BJT < 0 || BJT > 2359)
        return -1;
    if (BJT >= 100)
    {
        hour = BJT / 100;
        minute = BJT % 100;
        if (hour >= 8)
        {
            u_hour = hour - 8;
        }
        else
        {
            u_hour = 24 - (8 - hour);
        }
        u_minute = minute;
    }
    else
    {
        u_hour = 16;
        u_minute = BJT;
    }
    if (u_hour > 0 && u_minute >= 10)
    {
        printf("%d%d", u_hour, u_minute);
    }
    else if (u_hour == 0)
    {
        printf("%d", u_minute);
    }
    else if (u_hour != 0 && u_minute < 10)
    {
        printf("%d%d%d", u_hour, 0, u_minute);
    }
    return 0;
}

typedef struct
{
    char ms[20];
    char date[80];
    char random[20];
} sys_timestamp_t;

sys_timestamp_t stamp = {};

int sys_time_utc_date_get(void)
{
    char utc_time_buf[20] = {0};
    time_t utc_tim;
    time(&utc_tim);
    struct tm *p_time = gmtime(&utc_tim);
    strftime(utc_time_buf, sizeof(utc_time_buf), "%Y%m%d%H", p_time);

    return atoi(utc_time_buf);
}

int main()
{
    // printf("%d", get_time());

    // UTCToBeijing(0, 9, 3, 5, 38, 0);

    printf("%d\n", sys_time_utc_date_get());

    return 0;
}