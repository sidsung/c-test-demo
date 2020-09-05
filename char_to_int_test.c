#include <stdio.h>
#include <string.h>

int main()
{
    int time = 0;

    unsigned char data[10] = {0};

    sprintf(data, "%d", 10);

    printf("all : %s \n", data);

/*     for (int i = 0; i < 5; i++)
    {
        printf("%c\n", data[i]);
    } */

    char a = data[0];
    char b = data[1];

    a = a * 10 + b;
    printf("a : %d\n", a);
}
