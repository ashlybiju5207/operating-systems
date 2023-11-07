#include<stdio.h>
void main()
{
    int n,f,i,j,k,rs[100],m[50],count=0,pf=0;
    printf("Enter the length of reference string:");
    scanf("%d",&n);
    printf("\nEnter the reference string:");
    for (  i = 0; i < n; i++)
    {                                                                             //getting the necessary details from the user
         scanf("%d",&rs[i]);
    }
    printf("\nEnter the no frames:");
    scanf("%d",&f);
    for (i = 0; i < f; i++)
    {
        m[i]=-1;                                                                 // indicating the frame is empty
    }
    printf("\nThe page replacement process is:\n");
    //logic of FIFO
    for (  i = 0; i < n; i++)                                                       //iterating the rs loop
    {                        
         for (  k = 0; k < f; k++)                                                  // iteratting the frame loop
         {
             if (m[k]==rs[i])                                                       // checking if element in the rs is in one of the frames
             {
                 break;          //hit                                               // if present break the loop
             }
             
         }
         if ( k==f)                 //miss                                       // if rs is not found
         {
             m[count]=rs[i];      // then rs is added to the next available frame indicated by the count.Replace the first inserted eleement with the new string
             count++;             // count is incremented
             pf++;                 // page fault is indicated and is incremented
         }
         
         for (  j = 0; j < f; j++)                //printig the present state of frame
         {
            printf("\t%d",m[j]);
             
         }
         
         if ( k==f)                       //printing the page  fault  no if the condition satisfies
            {
                 printf("\tPage fault no:%d",pf);
                  
            }
            printf("\n");
            if (count==f)
            {
                 count=0;
                
            }
         
    }
    
    printf("\nThe no of page faults duringo FIFO page replacement are:%d",pf);
}