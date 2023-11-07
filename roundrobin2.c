#include<stdio.h>
void main()
{
    int n, bt[25],pid[25],qttime,tempbt[25],i,tat[25],at[25],wt[25],total=0;
    printf("Enter the no of processes:");
    scanf("%d",&n);
    printf("Enter the process id of all the processes:\n");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&pid[i]);
    }
    printf("Enter the burst time  of all the processes:\n");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&bt[i]);
         tempbt[i]=bt[i];
    }
    printf("Enter the arrival time  of all the processes:\n");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&at[i]);
          
    }

    printf("Enter the time slot of the proceses:\n");
    scanf("%d",&qttime);
}
while (1)
{
     int alldone=1;               //flag to check if all proceses are completed
     for (  i = 0; i < n; i++)
     {
         if (tempbt[i]>0)
         {
            alldone=0;            //still pending proceses
            if (tempbt[i]<=qttime)
            {
                  total=total+tempbt[i];
                  tempbt[i]=0;
            }
            else
            {
                total=total+tempbt[i];
                 tempbt[i]-=qttime;
            }
            
            
         }
         
     }
     
}


 
 