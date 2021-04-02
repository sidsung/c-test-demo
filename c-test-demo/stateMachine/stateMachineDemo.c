#include <stdio.h>
#include "stdint.h"

// typedef unsigned char uint8_t;
typedef uint8_t (*Procedure)(void *);

enum states
{
    s_init,
    s_count,
    s_done,
    s_default
}; //状态定义

typedef struct _SM_VAR //对状态机参数封装
{
    int cnt;
} sm_var_s;

uint8_t step_init(void *arg) //初始化
{
    sm_var_s *p = (sm_var_s *)arg;
    p->cnt = 0;
    printf("CS:init ;cnt=%d;NS:count\n", p->cnt);
    return s_count;
}

uint8_t step_count(void *arg) //计数
{
    sm_var_s *p = (sm_var_s *)arg;
    if (p->cnt < 3)
    {
        p->cnt += 1;
        printf("CS:count;cnt=%d;NS:count\n", p->cnt);
        return s_count;
    }
    else
    {
        printf("CS:count;cnt=%d;NS:done\n", p->cnt);
        return s_done;
    }
}

uint8_t step_done(void *arg) //计数完成
{
    sm_var_s *p = (sm_var_s *)arg;
    printf("CS:done ;cnt=%d;NS:init\n", p->cnt);
    return s_init;
}

uint8_t step_default(void *arg) //错误过程
{
    sm_var_s *p = (sm_var_s *)arg;
    printf("Wrong uint8_t\n");
    return s_init;
}

Procedure Steps[] = {step_init, step_count, step_done, step_default};

void BestStateMachine(void *invar)
{
    /* 定义下一状态 */
    static uint8_t NS = s_init; /* static局部变量只被初始化一次，下一次依据上一次结果值 */
    NS = Steps[NS](invar);
}

int main(void)
{
    sm_var_s var;
    int i;
    for (i = 0; i < 8; i++)
    { //给状态机8个周期的时钟驱动
        BestStateMachine(&var);
    }
    return 0;
}

/* 
CS:init ;cnt=0;NS:count
CS:count;cnt=1;NS:count
CS:count;cnt=2;NS:count
CS:count;cnt=3;NS:count
CS:count;cnt=3;NS:done
CS:done ;cnt=3;NS:init
CS:init ;cnt=0;NS:count
CS:count;cnt=1;NS:count 
*/