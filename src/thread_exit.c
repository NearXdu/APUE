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
    pthread_t *tid1=(pthread_t*)(arg);

    int ret = pthread_equal(*tid1,pthread_self());

    printf("in thread1 tid = %lu, ret is %d\r\n",(unsigned long)pthread_self(),ret);
    

    return ((void*)2);
}

void *thread2(void *arg)
{
    pthread_t *tid1=(pthread_t*)(arg);

    int *a= (int *)malloc(sizeof(int));
    printf("in thread2 pointer %p\r\n",a);
    *a=5;
    int ret = pthread_equal(*tid1,pthread_self());
    printf("in thread2 tid = %lu,ret is %d\r\n",(unsigned long)pthread_self(),ret);
    pthread_exit((void*)a);
}


int main(void )
{
#if 1
    pthread_t tid1;
    pthread_t tid2;

    int ret;
    ret = pthread_create(&tid1,NULL,thread1,&tid1);
    assert(ret==0);
    ret = pthread_create(&tid2,NULL,thread2,&tid1);//test
    assert(ret==0);

    printf("main thread:  %lu\r\n",(unsigned long)pthread_self());

    void * status;

    pthread_join(tid1,&status);
    printf("thread %lu exit status is %ld\r\n",(unsigned long)tid1,(long)status);



    int *fuck;
    pthread_join(tid2,(void*)&fuck);

    printf("======%d\r\n",*fuck);
    printf("in main pointer %p\r\n",fuck);
    free(fuck);

    //printf("thread %lu exit status is %d\r\n",(unsigned long)tid2,*(int *)status);

    printf("main thread exit\r\n");

#endif
    return 0;
}

