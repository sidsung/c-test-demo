#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "time.h"
#include "string.h"

typedef struct
{
    uint8_t needYear;
    uint8_t needMonth;
    uint8_t needDay;
    uint8_t needHour;
    uint8_t needMin;
    uint8_t needSec;
} sys_time_needed_s;

#define HL_TRUE 1
#define HL_FALSE 0

/**
 * @brief 以自定义格式返回当前时间, 如:年月日时分秒
 */
uint32_t sys_time_get_local_time(time_t ts, sys_time_needed_s *timeNeeded, char *localTime)
{
    char needStruct[20] = "";
    int len = 0;

    if (HL_TRUE == timeNeeded->needYear)
        len = sprintf(needStruct, "%s", "%Y");

    if (HL_TRUE == timeNeeded->needMonth)
        len = sprintf(needStruct + len, "%s", "%m");

    if (HL_TRUE == timeNeeded->needDay)
    {
        len += sprintf(needStruct + len, "%s", "%d");
        printf("len of day[%d]\n", len);
    }

    if (HL_TRUE == timeNeeded->needHour)
    {
        len += sprintf(needStruct + len, "%s", "%H");
        printf("len of hour[%d]\n", len);
    }

    if (HL_TRUE == timeNeeded->needMin)
    {
        len += sprintf(needStruct + len, "%s", "%M");
        printf("len of min[%d]\n", len);
    }

    if (HL_TRUE == timeNeeded->needSec)
    {
        len += sprintf(needStruct + len, "%s", "%S");
        printf("len of sec[%d]\n", len);
    }

    printf("%s\n", needStruct);

    if (ts == 0)
        time(&ts);

    strftime(localTime, 20, needStruct, localtime(&ts));

    printf("localTime[%s]\n", localTime);

    return HL_TRUE;
}

void time_change()
{
    int delaySec = 60;
    int localTime = 06170047; // 

    int a = delaySec / 60;
    

}

int main()
{
    // sys_time_needed_s timeNeededStruct = {
    //     .needYear = HL_FALSE,
    //     .needMonth = HL_FALSE,
    //     .needDay = HL_TRUE,
    //     .needHour = HL_TRUE,
    //     .needMin = HL_TRUE,
    //     .needSec = HL_TRUE,
    // };

    // char *localTime;
    // sys_time_get_local_time(1609434061, &timeNeededStruct, localTime);
    // printf("[%s]\n", localTime);

    // char iot_rec_ts[20] = "1234567891123";
    // time_t iot_ts = atoi(iot_rec_ts);
    // printf("%ld", iot_ts);


}