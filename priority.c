#include<stdio.h>
int main()
{
    int n,bt[15],wt[15],pid[15],i,j,tat[15],pt[15],pos,temp;
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
    
    //sorting of priority
    for (  i = 0; i < n; i++)
    {
         pos=i;
         for (  j = i+1; j < n; j++)
         {
            if(pt[j]>pt[pos])
            {
                pos=j;
            }
         }
         


        temp=pt[i];
        pt[i]=pt[pos];
        pt[pos]=temp;

        temp=pid[i];
        pid[i]=pid[pos];
        pid[pos]=temp;

     }

    wt[0]=0;
    //finding waitimg time of proceses
    for (  i = 1; i < n; i++)
    {   wt[i]=0;
         for (  j = 0; j < i; j++)
         {
             wt[i]+=bt[j];
         }
         
     }
    int t=0;
    printf("\nOrder of process execution\n");
    for (  i = 0; i < n; i++)
    {
         printf("P%d is executed from %d to %d",pid[i],t,t+bt[i]);
         t+=bt[i];
    }
    
     float twt=0.0;
     float ttat=0.0;
     printf("\n PROCESS ID     BURST TIME     PRIORITY     WAITING TIME     TURNAROUND TIME\n");
     for (  i = 0; i < n; i++)
     {
        printf("%d\t\t",pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t",pt[i]);
        printf("%d\t\t",wt[i]);

        //calculating turnaround time
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