#include<stdio.h>
int main()
{
    int n,pid[15],bt[15],wt[15],tat[15],i,j,pos,temp;
    printf("Enter the no of proceses:");
    scanf("%d",&n);
    printf("Enter the process id of all the proceses:");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&pid[i]);
    }
    
    
    printf("Enter the burst time :");
    for (  i = 0; i < n; i++)
    {
        scanf("%d",&bt[i]);
    }

    //sorting of burst times
    for (  i = 0; i < n; i++)
    {
        pos=i;
        for (  j = i+1; j < n; j++)
        {
             if (bt[j]<bt[pos])
             {
                 pos=j;
             }
             
        }
        
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=pid[i];
        pid[i]=pid[pos];
        pid[pos]=temp;

    }
    wt[0]=0;
    //finding waiting time of all proceses
    for (  i = 1; i < n; i++)
    {
         wt[i]=0;
        for ( j = 0; j < i; j++)
        {
           wt[i]+=bt[j];
        }
        
    }
    float twt=0.0;
    float ttat=0.0;
    printf("\nPROCESS ID     BURSTTIME     WAITING TIME     TURNAROUN TIME\n");
    for (  i = 0; i < n; i++)
    {
         printf("%d\t\t",pid[i]);
         printf("%d\t\t",bt[i]);
         printf("%d\t\t",wt[i]);

         //calculating turn around time
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