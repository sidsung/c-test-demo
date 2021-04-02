#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "stdint.h"
#include "string.h"

#define PRINT_DEBUG 1

typedef struct
{
    char crontab_minute[60]; /* 0-59                                 */
    char hour[24];   /* 0-23                                 */
    char crontab_day[32];    /* 0-31                                 */
    char crontab_month[12];  /* 0-11                                 */
    char crontab_week[8];    /* 0-6, beginning sunday                */
} crontab_s;

typedef struct
{
    int crontab_result_minute;
    int crontab_result_hour;
    int crontab_result_day;
    int crontab_result_month;
    int crontab_result_week[8];
} crontab_result_s;

// char crontab_input[] = {"36 14 2 9 1,3,5"};
// char crontab_input[] = {"20 * * * 1,3,5"};

int pro_crontab(char crontab_input[], crontab_s *time_rule, crontab_result_s *time_rule_result, int *week_num)
{
    int sub_min, sub_hour, sub_day, sub_month, sub_week;
    int *sub_num[5] = {&sub_min, &sub_hour, &sub_day, &sub_month, &sub_week};

    int blank_sub_flag = 0;
    for (int i = 0; i < strlen(crontab_input); i++)
    {
        if (' ' == crontab_input[i])
        {
            *sub_num[blank_sub_flag] = i;
#if PRINT_DEBUG
            // printf("sub_num[%d] = %d\n", blank_sub_flag, *sub_num[blank_sub_flag]);
#endif
            blank_sub_flag++;
        }
    }

    strncpy(time_rule->crontab_minute, crontab_input, sub_min);
    strncpy(time_rule->hour, crontab_input + sub_min + 1, sub_hour - sub_min - 1);
    strncpy(time_rule->crontab_day, crontab_input + sub_hour + 1, sub_day - sub_hour - 1);
    strncpy(time_rule->crontab_month, crontab_input + sub_day + 1, sub_month - sub_day - 1);
    strcpy(time_rule->crontab_week, crontab_input + sub_month + 1);
#if PRINT_DEBUG
    printf("crontab_minute : %s\nhour : %s\ncrontab_day : %s\ncrontab_month : %s\ncrontab_week : %s\n",
           time_rule->crontab_minute, time_rule->hour, time_rule->crontab_day, time_rule->crontab_month, time_rule->crontab_week);
#endif

    // char rule[10] = {0};
    // strcat(rule, time_rule.crontab_month);
    // strcat(rule, time_rule.crontab_day);
    // strcat(rule, time_rule.hour);
    // strcat(rule, time_rule.crontab_minute);
    // printf("****************************************************************************%s\n", rule);
    // printf("******************************************%d\n", atoi(rule));

    /*     crontab_result_s time_rule_result = {
        .crontab_result_minute = atoi(time_rule.crontab_minute),
        .crontab_result_hour = atoi(time_rule.hour),
        .crontab_result_day = atoi(time_rule.crontab_day),
        .crontab_result_month = atoi(time_rule.crontab_month),
    }; */
    time_rule_result->crontab_result_minute = atoi(time_rule->crontab_minute);
    time_rule_result->crontab_result_hour = atoi(time_rule->hour);
    time_rule_result->crontab_result_day = atoi(time_rule->crontab_day);
    time_rule_result->crontab_result_month = atoi(time_rule->crontab_month);

#if PRINT_DEBUG
    printf("crontab_result_minute : %d\ncrontab_result_hour : %d\ncrontab_result_day : %d\ncrontab_result_month : %d\n",
           time_rule_result->crontab_result_minute, time_rule_result->crontab_result_hour, time_rule_result->crontab_result_day,
           time_rule_result->crontab_result_month);
#endif

    int comma_sub_flag = 0;
    char week_sub_num[8] = {0};
    for (int i = 0; i < strlen(time_rule->crontab_week); i++)
    {
        if (',' != time_rule->crontab_week[i])
        {
            week_sub_num[comma_sub_flag] = time_rule->crontab_week[i];
#if PRINT_DEBUG
            // printf("week_sub_num[%d] = %s\n", comma_sub_flag, week_sub_num);
#endif
            comma_sub_flag++;
        }
    }
#if PRINT_DEBUG
    // printf("(char) week_sub_num = %s\n", week_sub_num);
#endif

    int week_sub_num_int = atoi(week_sub_num);
    *week_num = strlen(week_sub_num);
#if PRINT_DEBUG
    // printf("(int) week_sub_num_int = %d\n", week_sub_num_int);
#endif
    for (int i = 0; i < strlen(week_sub_num); i++)
    {
        time_rule_result->crontab_result_week[i] = week_sub_num_int % 10;
        week_sub_num_int /= 10;
        if (time_rule_result->crontab_result_week[i] == 0)
            time_rule_result->crontab_result_week[i] = 7;

#if PRINT_DEBUG
            // printf("time_rule_result.crontab_result_week[%d] = %d\n", i, time_rule_result.crontab_result_week[i]);
            // printf("week_sub_num_int : %d\n", week_sub_num_int);
#endif
    }

    /*     printf("***************time rule result******************\n");
    printf("excute local auto rule:\ndate:%d/%d/%d/%d\nweek:", time_rule_result->crontab_result_month, time_rule_result->crontab_result_day,
           time_rule_result->crontab_result_hour, time_rule_result->crontab_result_minute);
    for (int i = 0; i < strlen(week_sub_num); i++)
    {
        printf("week %d\t", time_rule_result->crontab_result_week[i]);
    }
    printf("\n***************time rule result******************\n"); */

    if (!strcmp(time_rule->crontab_week, "*"))
    {
        *week_num = 0;
        time_rule_result->crontab_result_week[0] = -1;
    }

    return 0;
}

int date_get(crontab_s *time_rule)
{
    int timeZone = 800;
    int autoTime = 0;

    printf("time_rule.hour = %s\n", time_rule->hour);
    printf("time_rule.crontab_minute = %s\n", time_rule->crontab_minute);

    int rule_len = 61;
    char rule[rule_len]; // 目前只设置小时和分钟
    // strcat(rule, time_rule.crontab_month);
    // strcat(rule, time_rule.crontab_day);
    // strcat(rule, time_rule->hour);
    // strcat(rule, time_rule->crontab_minute);

    int len = 0;
    len += snprintf(rule + len, rule_len - len, "%s", time_rule->hour);
    if (atoi(time_rule->crontab_minute) < 10)
        len += snprintf(rule + len, rule_len - len, "0%s", time_rule->crontab_minute);
    else
        len += snprintf(rule + len, rule_len - len, "%s", time_rule->crontab_minute);

    uint32_t value = atoi(rule);
    autoTime = (value + timeZone + 2400) % 2400;
    if (autoTime >= 2400)
        autoTime -= 2400;
    else if (autoTime < 0)
        autoTime += 2400;

    printf("autoTime = %d\n", autoTime);

    return autoTime;
}

int main(void)
{
    char crontab[] = "* * * * 0,1,2,3,4,5,6";
    // char crontab[] = {"* * * * 1,3,5,7,9"};
    crontab_result_s time_rule_result;
    int week_num = 0;
    crontab_s time_rule;
    memset(&time_rule, 0, sizeof(crontab_s));
    pro_crontab(crontab, &time_rule, &time_rule_result, &week_num);

    printf("***************time rule result******************\n");
    printf("excute local auto rule:\ndate:%d/%d/%d/%d\n", time_rule_result.crontab_result_month, time_rule_result.crontab_result_day,
           time_rule_result.crontab_result_hour, time_rule_result.crontab_result_minute);

    printf("week_num = %d\nweek:", week_num);
    for (int i = 0; i < week_num; i++)
    {
        printf("week %d\t", time_rule_result.crontab_result_week[i]);
    }
    printf("\n***************time rule result******************\n");

    printf("date = %d\n", date_get(&time_rule));
}