#include "stdio.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "stdint.h"

int main()
{
    for (int i = 0; i < 7; i++)
    {
        int a = rand() % 100;
        printf("%d : %d\n", i, a);
    }

    return 0;
}