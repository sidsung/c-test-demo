#include "stdio.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "stdint.h"

char cmdId[] = {"qwertyuiopasdfghjklzxcvbnm789012"};

int main()
{
    printf("cmdID len = %ld\n", strlen(cmdId));
    printf("cmdID size = %ld\n", sizeof(cmdId));
    return 0 ;
}