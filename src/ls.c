#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>
#include <malloc.h>

int main(int argc, char **argv)
{
    pid_t pid;
    if((pid=fork())<0)
    {
	printf("fork error\r\n");
	return -1;
    }
    else if(pid == 0)
    {
	printf("child  pid = %ld\r\n",(long)getpid());
	printf("child  uid = %ld\r\n",(long)getuid());
	printf("child  gid = %ld\r\n",(long)getgid());
//	execl("/bin/ls", "ls", "-l", (char *)0);
	execlp("ls", "ls", "-l", (char *)0);
    }
    else
    {
	int stat;
	pid_t pid=wait(&stat);
	printf("child terminate pid = %ld\r\n",(long)pid);
	printf("child terminate uid = %ld\r\n",(long)getuid());
	printf("child terminate gid = %ld\r\n",(long)getgid());
    }
    return 0;
}

