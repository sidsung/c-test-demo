#include "stdio.h"
#include "stdint.h"
#include "string.h"

#define STR_LEN 40

/**
  * @brief 1.回调函数参数 
  */
typedef struct
{
    int a_int;
    char b_str[STR_LEN];
} callback_param_s;

/**
 * @brief 2.回调函数
 */
typedef int (*callback_fun)(callback_param_s *str); /* 函数指针 */

/**
 * @brief 3.回调函数+参数的结构体
 */
typedef struct
{
    callback_param_s *param;
    callback_fun func;
} callback_fun_and_pam_s;

/**
 * @brief 4.定义回调函数和参数
 */
callback_fun_and_pam_s work_func;

/**
 * @brief 5.注册回调函数
 */
int callback_sign(callback_fun_and_pam_s *param_in)
{
    if (NULL == param_in)
    {
        printf("param in is null");
        return -1;
    }

    work_func.func = param_in->func;
    work_func.param = param_in->param;

    return 0;
}

/**
 * @brief 6.回调函数执行
 */
int callback_exeute(void)
{
    work_func.func(work_func.param);
    return 0;
}

/**
 * @brief 7.要执行的回调函数
 */
int callback(callback_param_s *param_in)
{
    if (NULL == param_in)
    {
        printf("param in is null");
        return -1;
    }

    char str[50] = "";
    snprintf(str, 50, "%s %d", param_in->b_str, param_in->a_int);
    printf("%s!!!", str);
    return 0;
}

/**
 * @brief 8.main
 */
int main()
{
    /* 1.注册回调函数及参数 */
    callback_param_s real_param = {
        .a_int = 110,
        .b_str = "please call",
    };

    callback_fun_and_pam_s real_func = {
        .func = callback,
        .param = &real_param,
    };

    /* 2.注册 */
    callback_sign(&real_func);

    /* 3.执行回调函数 */
    callback_exeute();
}
