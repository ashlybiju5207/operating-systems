#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    int pid1,pid2,pid3;
    pid1=fork();
    if ( pid1==-1)
    {
         printf("\nError on process creation\n");
    }
     if ( pid1!=0)
     {
        pid2=getpid();
        printf("The parent process id is %d",pid2);
     }
     else
     {
        pid3=getpid();
    printf("The child process id is %d");
     }
     
    
}