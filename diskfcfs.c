#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,rq[100],initial,thm=0,i;                       //initial to store the initial head position
    printf("Enter the no of requets:\n");
    scanf("%d",&n);
    printf("Enter the request sequence:");
    for ( i = 0; i < n; i++)
    {
         scanf("%d",&rq[i]);
    }
    printf("Enter the initial head position:\n");
    scanf("%d",&initial);

    //logic of fcfs

    for (  i = 0; i < n; i++)
    {
         thm+=abs(rq[i]-initial);          //thm is calculated by findiing the abs diff bw the current request and current head pos
         initial=rq[i];                    //the current head position is updated to the current request
    }
    

    printf("Total head moment:%d\n",thm);

    
}