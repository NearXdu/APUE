#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>
#include <malloc.h>
#include <signal.h>

static void sig_usr(int signo)
{
    if(signo == SIGUSR1)
    {
	printf("SIGUSR1 received\r\n");
    }
    else if(signo == SIGUSR2)
    {
	printf("SIGUSR2 received\r\n");
    }
    else
    {
	printf("received signal %d\r\n",signo);
    }
}

int main(int argc, char **argv)
{
    if(signal(SIGUSR1,sig_usr)==SIG_ERR)
    {
	printf("SIGUSR1 ERROR \r\n");
	return -1;
    }
    if(signal(SIGUSR2,sig_usr)==SIG_ERR)
    {
	printf("SIGUSR2 ERROR \r\n");
	return -1;
    }
    kill(getpid(),SIGUSR1);
    sleep(1);
    raise(SIGUSR2);
    sleep(1);
    raise(SIGINT);
    sleep(10);//
    return 0;
}


