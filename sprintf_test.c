#include <stdio.h>

char mac[5] = {'a', 'b', 'c', 'd', 'e'};

char submac[10] = {0};

int main()
{
    sprintf(submac, "%s%s", mac, "-0001");
    printf("the results are : %s", submac);
    return 0;
}