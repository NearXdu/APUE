#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>
#include <malloc.h>

int globvar=6;//全局变量
char buf[]="hello world\r\n";
int main(void )
{

#if 1
    int var;//栈上变量
    pid_t pid;
    var = 88;
    int *ptr=(int *)malloc(sizeof(int));
    *ptr=2;



    if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
    {
	printf("write error\r\n");
	return -1;
    }
    printf("before fork\r\n");

    if((pid=fork())<0)
    {
	printf("fork error");
	return -1;
    }
    else if(pid==0)//child 
    {
	++*ptr;
	++var;
	++globvar;
    }
    else//parent
    {
	sleep(2);
    }
    
    printf("pid = %ld, globvar = %d, &var = %ld , var = %d , *ptr = %d , ptr=%ld\r\n",(long)getpid(),globvar,(long)&var, var ,*ptr,(long)ptr);
    free(ptr);
#endif
    return 0;
}
