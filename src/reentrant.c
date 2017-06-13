#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>
#include <malloc.h>
#include <signal.h>
#include <pwd.h>

static void my_alarm(int signo)
{
    struct passwd	*rootptr;

    printf("in signal handler\n");
    if ((rootptr = getpwnam("root")) == NULL)
	err_sys("getpwnam(root) error");
    alarm(5);
}

int main(void)
{
    struct passwd	*ptr;

    signal(SIGALRM, my_alarm);
    alarm(1);
    for ( ; ; ) {
	if ((ptr = getpwnam("zhangxiao")) == NULL)
	    err_sys("getpwnam error");
	if (strcmp(ptr->pw_name, "zhangxiao") != 0)
	    printf("return value corrupted!, pw_name = %s\n",
		    ptr->pw_name);
    }
}
