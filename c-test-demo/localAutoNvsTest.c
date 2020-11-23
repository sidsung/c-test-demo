#include "stdio.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "stdint.h"

typedef struct
{
    uint32_t time;
    uint16_t action;
    uint32_t week[];
} timing_rule_s; // 本地智能结构体（时间、星期与动作）

typedef union
{
    char auto_id[33]; // 本条本地智能指令的ID号，每个插孔最多存储5条协议
    char sub_mac[18];
    char auto_type; // 本地智能下发的时控制光敏的还是定时的
    uint16_t week_num;
    timing_rule_s timing_rule;
    int ls_conl_rule;
} local_auto_rule_u;

int localAutoSet(local_auto_rule_u *autoRule)
{
    char ruleReslt[] = "";

    return 0;
}

int main()
{

    return 0;
}