#include <stdio.h>

char mac[5] = {'a', 'b', 'c', 'd', 'e'};

char submac[10] = {0};

char rule[] = "num_";
char rule_num[10] = "";
int num = 1;

void func()
{
    sprintf(rule_num, "%s%d", rule, num);
    printf("rule_num = %s\n", rule_num);
}

int main()
{
    func();

    // sprintf(submac, "%s%s", mac, "-0001");
    // printf("the results are : %s", submac);
    return 0;
}