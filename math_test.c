#include "stdio.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "stdint.h"

int main()
{
    int a = 20; //kwh
    float b = a * 1000; // wh
    b /= 1000;

    char c[] = "200.123";
    b = atof(c);

    printf("b = %.3f\n", b);
}