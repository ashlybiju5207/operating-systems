#include<stdio.h>
void main()
{
    int n,i,j,pid[25],bt[25],pt[25],temp,pos,at[25],wt[25],tat[25];
    printf("Enter the no of procesess:");
    scanf("%d",&n);
     printf("Enter the process id  of procesees:");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&pid[i]);
    }

    printf("Enter the burst time  of procesees:");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&bt[i]);
    }

    printf("Enter the priority of procesees:");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&pt[i]);
    }
    printf("Enter the arrival time of procesees:");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&at[i]);
    }
    //sorting of priority
    for (  i = 0; i < n; i++)
    {
         pos=i;
         for (  j = i+1; j < n; j++)
         {
             if (pt[j]>pt[pos])
             {
                 pos=j;
             }
             
         }

         temp=pt[i];
         pt[i]=pt[pos];
         pt[pos]=temp;

         temp=bt[i];
         bt[i]=bt[pos];
         bt[pos]=temp;

         temp=at[i];
         at[i]=at[pos];
         at[pos]=temp;

         temp=pid[i];
         pid[i]=pid[pos];
         pid[pos]=temp;
         
    }
    //calculating waiting time
    wt[0]=0;
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
    float ttat=0.0;
    float twt=0.0;
    printf("\nPROCESS ID     BURST TIME     ARRIVAL TIME     PRIORIT     YWAITING TIME     TURNAROUND TIME\n");
    for (  i = 0; i < n; i++)
    {
         printf("%d\t\t",pid[i]);
         printf("%d\t\t",bt[i]);
         printf("%d\t\t",at[i]);
         printf("%d\t\t",pt[i]);
         printf("%d\t\t",wt[i]);
         //calculating turnaround time
         tat[i]=wt[i]+bt[i];
         printf("%d\t\t",tat[i]);
         printf("\n");
         ttat+=tat[i];
         twt+=wt[i];

    }
    float awt=0.0;
    float atat=0.0;
    awt=twt/n;
    printf("Average waiting time:%f",awt);
    atat=ttat/n;
    printf("Average turnaround time:%f",atat);
    
    

    
    
}