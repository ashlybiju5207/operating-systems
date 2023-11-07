#include<stdio.h>
int main()
{
    int n,wt[15],bt[15],tat[15],i,pid[15],at[15];
    printf("Enter the no of processes:");
    scanf("%d",&n);
    printf("Enter the process id of all the proceses:");
    for (  i = 0; i <  n; i++)
    {
         scanf("%d",&pid[i]);
    }
    printf("Enter the arrival time of all the proceses:");
    for (  i = 0; i <  n; i++)
    {
         scanf("%d",&at[i]);
    }
    printf("Enter the burst time of all the proceses:");
    for (  i = 0; i <  n; i++)
    {
         scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for (  i = 1; i < n; i++)
    {
         wt[i]=wt[i-1]+bt[i-1]-at[i]+at[i-1];
    }
        float twt=0.0;
         float ttat=0.0;
    printf("\n PROCESS ID     BURST TIME     WAITING TIME     TURNAROUND TIME\n");
    for (  i = 0; i < n; i++)
    {
         printf("%d\t\t",pid[i]);
         printf("%d\t\t",bt[i]);
         printf("%d\t\t",wt[i]);
         tat[i]=wt[i]+bt[i];
         printf("%d\t\t",tat[i]);
         printf("\n");


          
         twt+=wt[i];
         ttat+=tat[i];

    }
     
    float awt=0.0;
    float atat=0.0;
    awt=twt/n;
    printf("Average waiting time:%f",awt);
    atat=ttat/n;

     
    printf("Average turnaround time:%f",atat);

    
}
