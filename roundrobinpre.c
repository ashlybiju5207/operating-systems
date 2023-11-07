#include<stdio.h>
void main()
{
    int n, bt[25],pid[25],qttime,tempbt[25],i,x,tat[25],at[25],wt[25];
    printf("Enter the no of processes:");
    scanf("%d",&n);
    x=n;
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

    int  total=0;
    float twt=0.0;
    float ttat=0.0;
     
    while (1)
    {
       int alldone=1;
    
    
    printf("\nPROCESS ID     BURST TIME     TURNAROUND TIME     ARRIVAL TIME     WAITING TIME\n");
    for (i=0;i<n;i++)
    {
      if (tempbt[i]>0)
      {
          alldone=0;

          if (tempbt[i]<=qttime)
         {
            total=total+tempbt[i];
            tempbt[i]=0;
             
         }
         else
         {
            
            tempbt[i]=tempbt[i]-qttime;
            total=total+qttime;
            
         }
         



      }
      
         
            
            printf("%d\t\t",pid[i]);
            printf("%d\t\t",bt[i]);
            tat[i]=total-at[i];
            printf("%d\t\t",tat[i]);
            printf("%d\t\t",at[i]);
            wt[i]=total-at[i]-bt[i];
            printf("%d\t\t",wt[i]);
            printf("\n");

            twt+=wt[i];
            ttat+=tat[i];
            

            if ( alldone)
            {
                break;
            }
            
             
         
            
       }
    }
        float awt =0.0;
         float atat=0.0;
         awt=twt/n;
         printf("Average waiting time :%f",awt);
         atat=ttat/n;
         printf("Average waiting time :%f",atat);
    
    
    
}