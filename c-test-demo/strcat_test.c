#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdint.h"

int main()
{
    int i = 123456;
    char time_count[4] = "";
    char time[20] = "timing_rule_week";

    // strcat(time, itoa(i, time_count, 10));
    itoa(i, time, 10);

    printf("%d\n", i);
    return 0;
}