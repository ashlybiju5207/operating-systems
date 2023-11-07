#include<stdio.h>
int main()
{
    int max[100][100],alloc[100][100],need[100][100],avail[100];
    int i,j,n,r ;
    printf("Enter the no of processes:");
    scanf("%d",&n);
    printf("Enter the no of resources:");
    scanf("%d",&r);
    printf("Enter the allocation matrix:");
    for (  i = 0; i < n; i++)
    {
        for (  j = 0; j < r; j++)
        {
            scanf("%d",&alloc[i][j]);
             
        }
        
         
    }

    

    
    printf("Enter the max matix:");
    for ( i = 0; i < n; i++)
    {
         for (  j = 0; j < r; j++)
         {
             scanf("%d",&max[i][j]);
         }
         
    }

    
    printf("Enter the avialable matrix:");
    for (  j = 0; j < r; j++)
    {
        scanf("%d",&avail[j]);
    }
     

    printf("The need matrix\n");
    for (  i = 0; i < n; i++)
    {
       for ( j = 0; j < r; j++)
       {
         need[i][j]=max[i][j]-alloc[i][j];
          
       }
       
    }
     
    //logic for bankers algorithm

    int k=0,flag;
    int finish[100],safeseq[100];
     
    for (  i = 0; i < n; i++)
    {
        finish[i]=0;  //declare all processes as incomplete
    }
    
    for (  i = 0; i < n; i++)
    {
         flag=0;
         if (finish[i]==0) //Execute incomplete processes
         {
             for (  j = 0; j < r; j++) //check neeed of each process
             {
                 if ( need[i][j] > avail[j])
                 {
                     flag=1;//break loop as need is greater than available go to next process
                     break;
                 }
                 else
                 {
                    flag=0;
                    break;
                 }
                 
             }

             if ( flag==0)//need is less than or equal to available so ccomplete process
             {
                 finish[i]=1;
                 safeseq[k]=i;
                 k++;
                 //add allocated resources to available processes
                 for (  j = 0; j < r; j++)
                 {
                     avail[j]=avail[j]+alloc[i][j];
                 }
                 //start checking from the first process again
                 i=-1;
             }
             
             
         }
         
    }
    flag=0;//check if all processes are completed
    for (  i = 0; i <  n; i++)
    {
         if (finish[i]==0)
         {
             printf("The system is in deadlock");
             flag=1;
             break;
         }
    }
         if ( flag==0)
         {
             printf("The system is in safe state");
             printf("The safe squence is\n");
             for (  i = 0; i <  n; i++)
             {
                 printf("P%d",safeseq[i]);
             }
             
         }
         
    
    

    
}
 