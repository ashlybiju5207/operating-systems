#include<stdio.h>
int main()
{
    int n,pid[15],bt[15],wt[15],tat[15],at[15],i,j,pos,temp;
    printf("Enter the no of proceses:");
    scanf("%d",&n);
    printf("Enter the process id of all the proceses:");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&pid[i]);
    }
    
    printf("Enter the arrival time :");
    for (  i = 0; i < n; i++)
    {
        scanf("%d",&at[i]);
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
         temp=pid[i];
         pid[i]=pid[pos];
         pid[pos]=temp;
          
         temp=bt[i];
         bt[i]=bt[pos];
         bt[pos]=temp;

          temp=at[i];
         at[i]=at[pos];
         at[pos]=temp;

         
    }

    wt[0]=0;                                //wt of first process is always 0
    for (  i = 1; i < n; i++)
    {
        wt[i]=0;
         for (  j = 0; j < i; j++)
         {
             wt[i]+=bt[j];
         }
         wt[i]-=at[i];
         if (wt[i]<0)
         {
             wt[i]=0;
         }
         
         
    }
    float twt=0.0;
    float ttat=0.0;
    printf("\nPROCESS ID     BURST TIME     ARRIVAL TIME     WAITING TIME     TURNAROUND TIME\n");
    for (  i = 0; i < n; i++)
    {
         printf("%d\t\t",pid[i]);
         printf("%d\t\t",bt[i]);
         printf("%d\t\t",at[i]);
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
         printf("average waitiing time:%f",awt);
         atat=ttat/n;
         printf("\naverage turnaround time:%f",atat);
    
    
    
}   