#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>
#include <malloc.h>
#include <signal.h>
    static void
sig_int(int signo)
{
    pr_mask("\nin sig_int: ");
}
    static void
sig_quit(int signo)
{
    pr_mask("\nin sig_quit: ");
}

int main(int argc,char **argv)
{
    sigset_t	newmask, oldmask, waitmask;

    pr_mask("program start: ");

    if (signal(SIGINT, sig_int) == SIG_ERR)
	err_sys("signal(SIGINT) error");
    if(signal(SIGQUIT,sig_quit)==SIG_ERR)
	err_sys("signal(SIGQUIT) error");

    //init to zero
    sigemptyset(&waitmask);
    //add SIGUSR1
    sigaddset(&waitmask, SIGUSR1);

    //init to zero
    sigemptyset(&newmask);
    //add SIGINT
    sigaddset(&newmask, SIGINT);

    //BLOCK SIGINT and save current sigsets
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
	err_sys("SIG_BLOCK error");

//    sleep(10);//will not receive SIGINT

#if 1

    /*
     * Critical region of code.
     */
    pr_mask("in critical region: ");

    /*
     * Pause, allowing all signals except SIGUSR1.
     */
    if (sigsuspend(&waitmask) != -1)
	err_sys("sigsuspend error");

    pr_mask("after return from sigsuspend: ");

    /*
     * Reset signal mask which unblocks SIGINT.
     */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
	err_sys("SIG_SETMASK error");

    /*
     * And continue processing ...
     */
    pr_mask("program exit: ");
#endif


    return 0;
}
