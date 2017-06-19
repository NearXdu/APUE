#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>
#include <malloc.h>
#include <pthread.h>
#include <assert.h>

void *thread1(void *arg)
{
    pthread_t *tid = (pthread_t*)arg;
    int ret= pthread_equal(*tid,pthread_self());
    printf("in thread: \r\n");
    printf("ret = %d, tid = %lu, tid = %lu\r\n",ret,(unsigned long)pthread_self(),(unsigned long)*tid);
    sleep(1);
    
}

int main(void )
{
    pthread_t tid;
    int ret=pthread_create(&tid,NULL,thread1,&tid);

    assert(ret==0);
    
    printf("main thread:  %lu\r\n",(unsigned long)pthread_self());


    sleep(5);
    pthread_join(tid,NULL);

    printf("main thread exit\r\n");
    
    return 0;
}
