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
    hour = UTChour - 7; //UTC+8转换为北京时间

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

int main()
{
    // printf("%d", get_time());

    UTCToBeijing(0, 9, 3, 12, 38, 0);

    return 0;
}