#include <time.h>
#include <stdio.h>
int main()
{
    time_t t;
    time(&t);
    printf("%ld\r\n",t);
    struct tm* tt=gmtime(&t);//格林时间
    struct tm* localtt=localtime(&t);
    printf("gm time: %s\r\n",asctime(tt));
    printf("local time: %s\r\n",asctime(localtt));
    printf("sec: %d\r\n",tt->tm_sec);
    printf("min: %d\r\n",tt->tm_min);
    printf("hour: %d\r\n",tt->tm_hour);
    printf("mday: %d\r\n",tt->tm_mday);
    printf("mon: %d\r\n",tt->tm_mon);
    printf("year: %d\r\n",tt->tm_year);
    printf("wday: %d\r\n",tt->tm_wday);
    printf("yday: %d\r\n",tt->tm_yday);
    return 0;
}
