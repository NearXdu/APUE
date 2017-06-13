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
    for(;;)
    {
	/*
	 * 
	 * pause()  causes the calling process (or thread) to sleep until a signal
	 * is delivered that either terminates the process or causes  the  invoca‐
	 * tion of a signal-catching function.
	 *
	 */
	pause();
    }
    return 0;
}


