#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,rq[100],initial,thm=0,i,j,pos,index,temp,size,move;                       //initial to store the initial head position
    printf("Enter the no of requets:\n");
    scanf("%d",&n);
    printf("Enter the request sequence:");
    for ( i = 0; i < n; i++)
    {
         scanf("%d",&rq[i]);
    }
    printf("\nEnter the initial head position:\n");
    scanf("%d",&initial);
    printf("\nEnter the max disk size:");
    scanf("%d",&size);
    printf("\nEnter the initial head movement direction(1 for high 0 for low):");
    scanf("%d",&move);

    //logic of scan

    for (  i = 0; i < n; i++)
    {
          pos =i;
         for (  j =i+1; j < n; j++)
         {
             if (rq[j]<rq[pos])
             {                                             //sorting of request array using selection sort
                   pos=j;
                   
             }
             
         }
                 temp=rq[i];
                rq[i]=rq[pos];
                rq[pos]=temp;

          
         
    }
    


    for (  i = 0; i < n; i++)                               //finding the index of first req seq that is greater than than the initial head
    {
        
        if (initial<rq[i])
        {
            index=i;
            break;
        }
        
    }


    //if initial movement is towards high
    if (move==1)
    {
         for (  i = index; i < n; i++)
         {
             thm+=abs(rq[i]-initial);
             initial=rq[i];
         }

         //moving to max disk size
         thm+=abs(size-rq[i-1]-1);
         initial=size-1;

         //moving in reverse direction
         for (  i = index-1; i >=0; i--)
         {
             thm+=abs(rq[i]-initial);
             initial=rq[i];
         }
          
         
    }
    else
    {
        //if initial head direction is low
         for (  i = index-1; i >=0; i--)
         {
             thm+=abs(rq[i]-initial);
             initial=rq[i];
         }

          //moving to min disk size
         thm+=abs(rq[i+1]-0);
         initial=0;

         //moving in reverse direction
         for (  i =index ; i <n ; i++)
         {
             thm+=abs(rq[i]-initial);
             initial=rq[i];
         }
    }

    printf("Total head moment:%d",thm);
    
    
}