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

     for (  i = 0; i < n; i++)   //sorting the request array
     { 
        pos=i;
         for (  j = i+1; j < n; j++)
         {
            if (rq[j]<rq[pos])
            {
                pos=j;
            }
             
         }
         
         temp=rq[i];
         rq[i]=rq[pos];
         rq[pos]=temp;
     }
     

     for (  i = 0; i < n; i++)                       //finding the index whose request is less than the initial head pos
     {
         if (initial<rq[j])
         {
             index=i;
         }
         
     }

     if (move==1)      //if movement is towards the high
     {
         for (  i = index; i < n; i++)
         {
            thm+=abs(rq[i]-initial);
            initial=rq[i];
         }
         //moving to the max disk size
         thm+=abs(size-rq[i-1]-1);
         //moving to the min disk size
         thm+=abs(size-1-0);
         initial=0;
         //circular addressing
         for (  i = 0; i < index; i++)
         {
            thm+=abs(rq[i]-initial);
            initial=rq[i];
         }
         
         
     }
     

     else                                                 //if movement toowards low
     {
         for (  i = index; i >=0; i--)
         {
             thm+=abs(rq[i]-initial);
             initial=rq[i];
         }
         //moving to min disk size
         thm+=abs(rq[i+1]-0);
         //moving to max disk size
         thm+=abs(size-1-0);
         initial=size-1;


         //circular addressing
         for (  i = n-1; i>=index; i--)
         {
             thm+=abs(rq[i]-initial);
             initial=rq[i];
         }
         

     }
     printf("\nTotal head moment :%d",thm);
     
     
}