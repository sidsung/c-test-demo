#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "time.h"
#include "string.h"

char b[] = "HTTP/1.1 200 OKDate: Tue, 09 Feb 2021 03:43:53 GMTContent-Type: application/json; charset=utf-8Content-Length: 809Connection: keep-alive{  \"code\": \"1\",  \"msg\": \"Success\",  \"data\": {    \"coord\": {      \"lon\": 117.1236,      \"lat\": 39.1159    },    \"weather\": [      {        \"id\": 800,        \"main\": \"Clear\",        \"description\": \"clear sky\",        \"icon\": \"01d\"      }    ],    \"base\": \"stations\",    \"main\": {      \"temp\": 279.15,      \"feels_like\": 272.76,      \"temp_min\": 279.15,      \"temp_max\": 279.15,      \"pressure\": 1025,      \"humidity\": 36    },    \"visibility\": 10000,    \"wind\": {      \"speed\": 5,      \"deg\": 240    },    \"clouds\": {      \"all\": 0    },    \"dt\": 1612842232,    \"sys\": {      \"type\": 1,      \"id\": 9619,      \"country\": \"CN\",      \"sunrise\": 1612825833,      \"sunset\": 1612863659    },    \"timezone\": 28800,    \"id\": 1792947,    \"name\": \"Tianjin\",    \"cod\": 200  }}";

int func()
{
    char a[1000] = "{\"ts\":1612842251963,\"code\":\"1\",\"msg\":\"\",\"data\":{\"device_auto_info\":[{\"triggers\":{\"data\":\"* * * * 0,1,2,3,4,5,6\",\"key\":\"sunrise\",\"is_enable\":1,\"is_repeat\":1},\"actions\":{\"key\":\"turn_on\"},\"auto_Id\":\"9b92ac47494f4516ac5cdf90544e4ed6\",\"sub_mac\":\"2CAA8EB8D89C-0002\"},{\"triggers\":{\"data\":\"* * * * 0,1,2,3,4,5,6\",\"key\":\"sunset\",\"is_enable\":1,\"is_repeat\":1},\"actions\":{\"key\":\"turn_off\"},\"auto_Id\":\"9b92ac47494f4516ac5cdf90544e4ed6\",\"sub_mac\":\"2CAA8EB8D89C-0002\"},{\"triggers\":{\"data\":\"* * * * 0,1,2,3,4,5,6\",\"key\":\"photosensitiveoff\",\"is_enable\":0,\"is_repeat\":1},\"actions\":{\"key\":\"turn_on\"},\"auto_Id\":\"f15814e87c2a48f2adfda615163e5817\",\"sub_mac\":\"2CAA8EB8D89C-0002\"},{\"triggers\":{\"data\":\"* * * * 0,1,2,3,4,5,6\",\"key\":\"photosens\"";
    int c = 7;
    char d[7] = "";
    sprintf(d, "%d", c);
    printf("%s", d);
    return 0;
}

int main()
{
    func();
    return 0;
}