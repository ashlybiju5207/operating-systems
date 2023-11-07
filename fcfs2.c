#include<stdio.h>
void main()
{
    int n,pid[25],bt[25],wt[25],i,tat[25];
    printf("Enter the no of processes:\n");
    scanf("%d",&n);
    printf("Enter the process id of all the proceses:\n");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&pid[i]);

    }
    printf("Enter the burst time of all the proceses:\n");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&bt[i]);
         
    }
    printf("Enter the waiting  time of all the proceses:\n");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&wt[i]);
         
    }

    //logic of fcfs

    wt[0]=0;                                    //in fcfs the first process does not have to wait
    for (  i = 1; i < n; i++)
    {
         wt[i]=wt[i-1]+bt[i-1];                 //calculating the waiting time
    }
    float twt=0.0;
    float ttat=0.0;
    printf("\nPROCESS ID     WAITING TIME     BURST TIME     TURNAROUND TIME\n");
    for (  i = 0; i < n; i++)
    {
         printf("%d\t\t",pid[i]);
         printf("%d\t\t",wt[i]);
         printf("%d\t\t",bt[i]);

         tat[i]=wt[i]+bt[i];                    //calculating the turnaround time
         printf("%d\t\t",tat[i]);
         printf("\n");

         twt+=wt[i];                             //calcualating total waiting time and total turnaround time
         ttat+=tat[i];
         
    }
    
    float awt=0.0;
    float atat=0.0;
    awt=twt/n;
    printf("The average waiting time :%f\n",awt);
    atat=ttat/n;
    printf("the average turn around time:%f\n",atat);
    
}