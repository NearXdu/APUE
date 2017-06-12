#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t pid;
    if((pid=fork())<0)//error
    {
	printf("fork error!");
	return -1;
    }
    else if(pid==0)//child
    {
	printf("in child\r\n");
	sleep(2);
    }
    else
    {
	sleep(5);
	int stat;
	pid_t pid=wait(&stat);
	printf("child terminate pid = %ld\r\n",(long)pid);

    }
    return 0;
}
