#include <stdio.h>    
#include <sys/wait.h>    
#include <sys/types.h>    
#include <unistd.h>    

int main(void)       
{       
    pid_t pid;       

    if ((pid = fork()) < 0)   //error    
    {       
	fprintf(stderr,"Fork error!\r\n");       
	exit(-1);       
    }       
    else if (pid == 0) //第一个子进程  
    {        
	if ((pid = fork()) < 0)      //在第一个子进程中fork
	{        
	    fprintf(stderr,"Fork error!/n");       
	    exit(-1);       
	}       
	else if (pid > 0) //第一个子进程，也就是第二个子进程的父进程      
	    exit(0); /* parent from second fork == first child */      
	//直接退出
	/*    
	 * We're the second child; our parent becomes init as soon    
	 * as our real parent calls exit() in the statement above.    
	 * Here's where we'd continue executing, knowing that when    
	 * we're done, init will reap our status.    
	 */   
	sleep(2);       
	printf("Second child, parent pid = %d\r\n", getppid());       
	exit(0);       
    }       

    if (waitpid(pid, NULL, 0) != pid) /* wait for first child */      
    {       
	fprintf(stderr,"Waitpid error!\r\n");       
	exit(-1);       
    }       

    /*    
     * We're the parent (the original process); we continue executing,    
     * knowing that we're not the parent of the second child.    
     */      
    exit(0);       
}       
