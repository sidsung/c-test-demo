/* 参考链接：http://c.biancheng.net/view/2054.html */

#include "stdio.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"

#define LOG_SOURCE_DIR "C:\\Users\\fraki\\Desktop\\logReview\\logSource\\"
#define LOG_TARGET_DIR "C:\\Users\\fraki\\Desktop\\logReview\\logAllTogether\\"
#define LOG_FILE_TYPE ".txt"
#define LOG_RES_DIR_LEN 50
#define LOG_DES_DIR_LEN 100

int get_log_source_dir(char logResDir[LOG_RES_DIR_LEN], int fileName)
{
    if (NULL == logResDir)
    {
        printf("%d logResDir input error", __LINE__);
        exit(0);
    }

    memset(logResDir, 0, strlen(logResDir));
    strcat(logResDir, LOG_SOURCE_DIR);
    sprintf(logResDir + strlen(LOG_SOURCE_DIR), "%d", fileName);
    strcat(logResDir, LOG_FILE_TYPE);

    return 0;
}

int get_log_target_dir(char logDesDir[LOG_DES_DIR_LEN])
{
    if (NULL == logDesDir)
    {
        printf("%d logDesDir input error", __LINE__);
        exit(0);
    }

    memset(logDesDir, 0, LOG_DES_DIR_LEN);
    strcat(logDesDir, LOG_TARGET_DIR);

    char timeNow[20];
    memset(timeNow, 0, sizeof(timeNow));
    time_t ts;
    time(&ts);
    strftime(timeNow, sizeof(timeNow), "%Y%m%d%H%M", localtime(&ts));
    strcat(logDesDir, timeNow);

    strcat(logDesDir, LOG_FILE_TYPE);

    return 0;
}

int copy_file()
{
    FILE *logSource;
    FILE *logTarget;
    char logCh = 0;
    int fileName = 0;

    char logResDir[LOG_RES_DIR_LEN];
    char logDesDir[LOG_DES_DIR_LEN];

    get_log_target_dir(logDesDir);

    do
    {
        fileName++;
        get_log_source_dir(logResDir, fileName);
        logSource = fopen(logResDir, "r");

        if (NULL == logSource)
            goto RETURN;

        printf("log source: %s\n", logResDir);

        if (NULL == logTarget)
        {
            logTarget = fopen(logDesDir, "at+");

            if (NULL == logTarget)
            {
                puts("Fail to creat target file!");
                exit(0);
            }
        }

        while (EOF != (logCh = fgetc(logSource)))
        {
            fputc(logCh, logTarget);
        }
        fclose(logSource);

    } while (NULL != logSource);

RETURN:
    fclose(logTarget);

    return 0;
}

int main()
{
    copy_file();
    printf("done!");
    return 0;
}