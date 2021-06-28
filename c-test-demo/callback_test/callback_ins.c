#include "stdio.h"
#include "stdint.h"

/************************************************************************************
回调函数+参数结构体
声明：下层
定义：下层
************************************************************************************/
typedef int (*p_output)(char *str);//函数指针

typedef struct fun_parameter{       
    char    *pam;//函数的传参
    p_output fun;//函数
}fun_parameter_t;

fun_parameter_t  work_fun;//定义在下层 work_fun.pam   work_fun.fun
/************************************************************************************
回调函数
定义：上层
调用：下层
************************************************************************************/
int callback(char *in) 
{
    printf("High level: callback response with parameter: %s\n", in); 
    return 0;
}
/************************************************************************************
注册函数
定义：下层
调用：上层
************************************************************************************/
void callback_sign(fun_parameter_t *in) 
{
    work_fun.fun = in->fun;
    work_fun.pam = in->pam;
    printf("Lower level: callback sign\n");
    return; 
}
/************************************************************************************
执行函数
定义：下层
调用：下层
************************************************************************************/
void callback_execute(void) 
{
    printf("Lower level: callback execute\n");
    // return work_fun.fun(work_fun.pam);   
    work_fun.fun(work_fun.pam);
    return;
}
/************************************************************************************
主函数
************************************************************************************/
int main()
{
    //在上层注册
    printf("main: step 1 :sign callback\n");
    fun_parameter_t temp_fun={
        .pam="ok", 
        .fun=callback
    }; 
    callback_sign(&temp_fun);//完成注册
    
    //在下层执行
    printf("main: step 2 :execute fun\n");
    int count = 1;
    while(1)
    {
        count ++;
        if(count % (521 * 1000000000) == 0)
        {
            callback_execute();
        }
    }       
}