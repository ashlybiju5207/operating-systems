#include<stdio.h>
int main()
{
    int n,bt[15],wt=0,pid[15],i,tat=0,pt[15],tempbt[15],x,qttime,at[i];
     printf("Enetr the total no of processses:");
     scanf("%d",&n);
     x=n;

     //input details of process
     for (  i = 0; i < n; i++)
     {
          printf("Enter the details of process%d",i+1);
          printf("Enter the process id:");
          scanf("%d",&pid[i]);
          printf("arrival time:");
          scanf("%d",at[i]);
          printf("Burst time:");
          scanf("%d",&bt[i]);
          tempbt[i]=bt[i];   //to store a copy of burst time

     }
     //input timme slot
     printf("Enter the time slot:");
     scanf("%d",&qttime);
     //total indicates total time elapsed
     //count indicates whiich process is executed
    int total=0;    
    int count=0;
    
     printf("\n PROCESS ID     BURST TIME          TURNAROUND TIME     WAITING TIME      \n");
     for (  total = 0; i =0; x!=0)    //loop continuues until process have completed execution
     {
            if ( tempbt[i]<=qttime && tempbt[i]>0)   //checking if bt is less than or equal to the time qt
            {
                total=total+tempbt[i]; //total time elapsed is incremented by the remaining burst time, and the remaining burst time is set to 0.
                tempbt[i]=0;
                count=1;
            }


            else if (tempbt[i]>0)
            {
                tempbt[i]=tempbt[i]-qttime;  //If the remaining burst time is greater than the time quantum,
                                            // it is decremented by the time quantum, and the total time elapsed is incremented by the time quantum
                total=total+qttime;
            }

            if (tempbt[i]==0 && count==1)  //If a process completes execution (i.e., its remaining burst time reaches 0), its turnaround and waiting times are calculated and printed to the screen.
            {
                x--;
                printf("%d\t\t",pid[i]);
                printf("%d\t\t", bt[i]);
                printf("%d\t\t",total-at[i]);

                //calculating waiting time
                printf("%d\t\t",total-at[i]-bt[i]);
                printf("\n");

                
            

                 wt=wt+total-at[i]-bt[i];
                 tat=tat+total-at[i];
                 count=0;

            }
             if(i==n-1)  
             {  
             i=0;  
            }  
             else if(at[i+1]<=total)  
            {  
            i++;  
            }  
            else  
            {  
            i=0;  
            }  
            
         

     }

     float awt= wt*1.0/n;
     float atat=tat*1.0/n;
     
     printf("Average waiting time:%f",awt);
     
     printf("Average turnaround time:%f",atat);
      

    return 0;
    
}