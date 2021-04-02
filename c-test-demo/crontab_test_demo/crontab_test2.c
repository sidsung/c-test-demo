#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "stdint.h"
#include "string.h"

typedef struct
{
    char minute[3];
    char hour[3];
    char day[3];
    char month[3];
    char week[8];
} crontab_s;

typedef struct
{
    uint8_t minute;
    uint8_t hour;
    uint8_t day;
    uint8_t month;
    uint8_t week[8];
    uint8_t weekNum;
} crontab_result_s;

static void remove_chars(char *str, char c)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != c)
        {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = 0;
}

int crontab_prase(char test[], crontab_s *crontab)
{
    char *blank[4];
    blank[0] = test;

    int i = 0;
    for (i = 0; i < 4; i++)
    {
        blank[i] = strchr(blank[((0 == i) ? i : (i - 1))] + 1, ' ');

        // printf("blank[%d][%s]\n", i, blank[i]);

        switch (i)
        {
        case 0:
            memset(crontab->minute, 0, sizeof(crontab->minute));
            memcpy(crontab->minute, test, blank[i] - test);
            printf("minute[%s]\n", crontab->minute);
            break;
        case 1:
            memset(crontab->hour, 0, sizeof(crontab->hour));
            memcpy(crontab->hour, blank[i - 1] + 1, blank[i] - blank[i - 1] - 1);
            printf("hour[%s]\n", crontab->hour);
            break;
        case 2:
            memset(crontab->day, 0, sizeof(crontab->day));
            memcpy(crontab->day, blank[i - 1] + 1, blank[i] - blank[i - 1] - 1);
            printf("day[%s]\n", crontab->day);
            break;
        case 3:
            memset(crontab->month, 0, sizeof(crontab->month));
            memcpy(crontab->month, blank[i - 1] + 1, blank[i] - blank[i - 1] - 1);
            printf("month[%s]\n", crontab->month);
            break;
        default:
            break;
        }
    }

    char *week = blank[3] + 1;
    remove_chars(week, ',');
    printf("week[%s]\n", week);
    memcpy(crontab->week, week, sizeof(crontab->week));

    return 0;
}

int auto_time_prase(crontab_s *crontab, crontab_result_s *result, int timeZone, int *autoTime)
{
    result->minute = atoi(crontab->minute);
    result->hour = atoi(crontab->hour);
    result->day = atoi(crontab->day);
    result->month = atoi(crontab->month);
    result->weekNum = strlen(crontab->week);

    printf("excute local auto rule:\ndate:%d/%d/%d/%d\n", result->month,
           result->day, result->hour, result->minute);

    if (!strcmp(crontab->week, "*"))
    {
        result->weekNum = 0;
        result->week[0] = -1;
    }
    else
    {
        int week_sub_num_int = atoi(crontab->week);
        int i = 0;
        for (i = 0; i < result->weekNum; i++)
        {
            result->week[i] = week_sub_num_int % 10;
            week_sub_num_int /= 10;
        }
    }
    printf("\n");

    int rule_len = 61;
    char rule[rule_len];
    int len = 0;
    len += snprintf(rule + len, rule_len - len, "%s", crontab->hour);
    if (atoi(crontab->minute) < 10)
        len += snprintf(rule + len, rule_len - len, "0%s", crontab->minute);
    else
        len += snprintf(rule + len, rule_len - len, "%s", crontab->minute);

    uint32_t value = atoi(rule);
    *autoTime = (value + timeZone + 2400) % 2400;
    if (*autoTime >= 2400)
        *autoTime -= 2400;
    else if (*autoTime < 0)
        *autoTime += 2400;

    printf("***************time rule result******************\n");
    printf("date:%d/%d/%d/%d\n", result->month,
           result->day, result->hour, result->minute);
    printf("autoTime = %d\n:", *autoTime);
    printf("weekNum = %d\nweek:", result->weekNum);
    for (int i = 0; i < result->weekNum; i++)
    {
        printf("week %d\t", result->week[i]);
    }
    printf("\n***************time rule result******************\n");

    return 0;
}

int main()
{
    char test[] = "59 23 * * 2,3";
    int timeZone = 800;
    int autoTime = 0;

    crontab_s crontab;
    memset(&crontab, 0, sizeof(crontab_s));
    crontab_result_s result;
    memset(&result, 0, sizeof(crontab_result_s));

    crontab_prase(test, &crontab);

    auto_time_prase(&crontab, &result, timeZone, &autoTime);

    printf("autoTime[%d]\n", autoTime);

    return 0;
}