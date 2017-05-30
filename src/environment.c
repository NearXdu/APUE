#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    const char * home="HOME";
    char *penv=getenv(home);
    char buf[128];
    sprintf(buf,"ZHANGXIAO=%s",penv);

    int ret=putenv(buf);
    assert(ret==0);

    penv=getenv("ZHANGXIAO");
    printf("%s\r\n",penv);


    ret = setenv("ZHANGXIAO","new value",0);
    assert(ret==0);

    penv=getenv("ZHANGXIAO");
    printf("%s\r\n",penv);

    ret = setenv("ZHANGXIAO","new value",1);
    assert(ret==0);

    penv=getenv("ZHANGXIAO");
    printf("%s\r\n",penv);

    return 0;
}
