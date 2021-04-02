#include <stdio.h>
#include <time.h>

int main()
{
    char buf[25];
    // time_t yest = time(NULL) - (time_t)(60 * 60 * 24);
    time_t yest = 1609459261 - (time_t)(60 * 60 * 24);

    strftime(buf, 24, "%Y-%m-%d %H:%M:%S", gmtime(&yest));
    
    printf("%s\n", buf);
    
    strftime(buf, 24, "%Y-%m-%d %H:%M:%S", gmtime(&yest));
    
    printf("%s\n", buf);
}