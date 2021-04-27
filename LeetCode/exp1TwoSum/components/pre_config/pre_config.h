/* 预定义一些宏，可在其他文件直接调用 */

#ifndef __PRE_CONFIG_H_
#define __PRE_CONFIG_H_

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "assert.h"
#include <unistd.h>

typedef enum
{
    HL_FAIL = -1, /* Fail. */
    HL_OK,        /* Ok. */
} hl_result_e;

typedef enum
{
    LOG_DEBUG = 0,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
} log_level_e; /* log等级 */

#ifndef __ASSERT_FUNC
#ifdef __ASSERT_FUNCTION
#define __ASSERT_FUNC __ASSERT_FUNCTION
#else
#define __ASSERT_FUNC "??"
#endif
#endif

/**
 * @brief 返回值检查，不为HL_OK将暂停程序
 */
#define HL_CHECK_ERROR(functionCall)                                   \
    {                                                                  \
        hl_result_e hlResult = (functionCall);                         \
        if (HL_OK != hlResult)                                         \
        {                                                              \
            printf("file: \"%s\" line %d\nfunc: %s\nexpression: %s\n", \
                   __FILE__, __LINE__, __ASSERT_FUNC, #functionCall);  \
            pause();                                                   \
        }                                                              \
    }

/**
 * @brief 
 */
#define HL_CHECK_RESULT(functionCall)          \
    {                                          \
        hl_result_e hlResult = (functionCall); \
        if (HL_OK != hlResult)                 \
            return hlResult;                   \
    }

/**
 * @brief 设置log打印等级，默认DEBUG等级
 */
hl_result_e pre_config_set_log_level(log_level_e logLevel);

/**
 * @brief 获取log打印等级
 */
log_level_e pre_config_get_log_level(void);

/**
 * @brief 打印log
 */
#define hlLogPrint(info...)                                \
    {                                                      \
        printf("[%s %s %d]", TAG, __FUNCTION__, __LINE__); \
        printf(info);                                      \
        printf("\n");                                      \
    }

/**
 * @brief 打印 DEBUG log
 */
#define hlLogDebug(info...)                          \
    {                                                \
        if (LOG_DEBUG >= pre_config_get_log_level()) \
        {                                            \
            printf("[DEBUG]");                       \
            hlLogPrint(info);                        \
        }                                            \
    }

/**
 * @brief 打印 INFO log
 */
#define hlLogInfo(info...)                          \
    {                                               \
        if (LOG_INFO >= pre_config_get_log_level()) \
        {                                           \
            printf("[INFO]");                       \
            hlLogPrint(info);                       \
        }                                           \
    }

/**
 * @brief 打印 WARNING log
 */
#define hlLogWarning(info...)                          \
    {                                                  \
        if (LOG_WARNING >= pre_config_get_log_level()) \
        {                                              \
            printf("[WARNING]");                       \
            hlLogPrint(info);                          \
        }                                              \
    }

/**
 * @brief 打印 ERROR log
 */
#define hlLogError(info...)                          \
    {                                                \
        if (LOG_ERROR >= pre_config_get_log_level()) \
        {                                            \
            printf("[ERROR]");                       \
            hlLogPrint(info);                        \
        }                                            \
    }

#endif /* __PRE_CONFIG_H_ */