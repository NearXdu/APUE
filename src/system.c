#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>
#include <malloc.h>
#include <signal.h>

int main(int argc,char **argv)
{
    system("ls -lh > fuck.txt");

    return 0;
}

