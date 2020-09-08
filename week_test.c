#include <stdio.h>
#include "stdlib.h"
#include "stdint.h"
#include "time.h"

typedef struct week_test
{
    int year;
    int month;
    int day;
    int hour;
    int week;
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
    char ctime_buf_h[20] = "";

    time(&tim);
    // strftime(ctime_buf, 20, "%Y%m%d", localtime(&tim));
    strftime(ctime_buf_y, 20, "%Y", localtime(&tim));
    local_date->year = atoi(ctime_buf_y);

    strftime(ctime_buf_m, 20, "%m", localtime(&tim));
    local_date->month = atoi(ctime_buf_m);

    strftime(ctime_buf_d, 20, "%d", localtime(&tim));
    local_date->day = atoi(ctime_buf_d);

    strftime(ctime_buf_h, 20, "%H", localtime(&tim));
    local_date->hour = atoi(ctime_buf_h);

    struct tm *date = gmtime(&tim);
    local_date->week = date->tm_wday;
    
    printf("%d - %d - %d - %d\n", local_date->year, local_date->month, local_date->day, local_date->hour);
    printf("week : %d\n", local_date->week);

    return 0;
}

int main()
{
    int day, mn, yr, i, days = 0, s, k;
    int mont[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // char wek[][9] = {{'S', 'u', 'n', 'd', 'a', 'y'},
    //                  {'M', 'o', 'n', 'd', 'a', 'y'},
    //                  {'T', 'u', 'e', 's', 'd', 'a', 'y'},
    //                  {'W', 'e', 'd', 'n', 's', 'd', 'a', 'y'},
    //                  {'T', 'h', 'u', 'r', 's', 'd', 'a', 'y'},
    //                  {'F', 'r', 'i', 'd', 'a', 'y'},
    //                  {'S', 'a', 't', 'u', 'r', 'd', 'a', 'y'}};
    int wek[7] = {7, 1, 2, 3, 4, 5, 6};
    // printf("Inpute the date (year-month-day):");
    // scanf("%d-%d-%d", &yr, &mn, &day);202009041712

    // printf("%d\n", get_local_time());

    localtime_s local_date;
    get_local_time(&local_date);

    yr = local_date.year;
    mn = local_date.month;
    day = local_date.day;

    if (yr % 4 == 0 || yr % 100 == 0 || yr % 400 == 0)
        mont[2] = 29;
    else
        mont[2] = 28;
    for (i = 0; i < mn; i++)
        days += mont[i];
    days += day;
    s = yr - 1 + (int)((yr - 1) / 4) - (int)((yr - 1) / 100) + (int)((yr - 1) / 400) + days;
    k = s % 7;
    printf("%d-%d-%d is %d.\n", yr, mn, day, wek[k]);
    return 0;
}