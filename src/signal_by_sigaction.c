#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>
#include <malloc.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

sighandler_t MySignal(int signo,sighandler_t handler)
{
    struct sigaction act,oact;

    sigset_t mask;
    sigemptyset(&mask);
    

    act.sa_handler=handler;
    act.sa_mask=mask;
    act.sa_flags |= SA_RESTART;


    if(sigaction(signo,&act,&oact)<0)
	return SIG_ERR;

    return oact.sa_handler;

    
}

static void sig_handler(int signo)
{
    printf("in sig handler\r\n");
}

int main(int argc, char **argv)
{
    MySignal(SIGALRM,sig_handler);
    alarm(5);
    pause();
    
    return 0;
}


