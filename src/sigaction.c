#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>


static void sig_usr(int signo)
{
    printf("in signal handler\r\n");
    sleep(20);
}

int main(int argc ,char **argv)
{
    struct sigaction sa_usr;

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask,SIGINT);
    

    sa_usr.sa_handler=sig_usr;
    sa_usr.sa_mask=mask;
    sa_usr.sa_flags=0;

    sigaction(SIGUSR1,&sa_usr,NULL);
    pause();

    return 0;
}
