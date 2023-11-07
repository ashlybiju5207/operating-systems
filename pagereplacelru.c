#include<stdio.h>
void main()
{
    int n,f,i,j,k,rs[25],m[25],count[50],flag[25],pf=0,min,next=0;
    printf("\nEnter the length of reference string:");
    scanf("%d",&n);
    printf("\nEnter the refrence string:");                                 //gettiing details from the user
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&rs[i]);
         flag[i]=0;                           //flag array is used to keep track of page fault.if pf occur then flag=0 else flag=1  
          
    }
    
    printf("Enter the no of frames:");
    scanf("%d",&f);
    for (  i = 0; i < f; i++)
    {
         m[i]=-1;                    //indicating that all frames are empty in the begining
        count[i]=0;                //count array is used to keep track of the time of last use of each frame                                      
    }

    printf("\nThe page replacement process is:\n");
                                           
    for (  i = 0; i < n; i++)               //iterating through rs
    {
        for (  j = 0; j < f; j++)           // itreating through frame
        {
            if (m[j]==rs[i])                //checking if each element in rs is present in one of the frames 
            {
                 flag[i]=1;                 // if present pf does not occur
                 count[j]=next;             // time of last use of  this frame is updated and next is incremented
                 next++;                 
            }
            
        }

        if (flag[i]==0)                     // if page fault occur ie if flag=0 after checking all frames
        {
            if (i<f)                        // if i<f there are still empty frames available. no replacement necessary
            {
                 m[i]=rs[i];                // the current element in rs is simply loaded into the empty frame
                 count[i]=next;
                 next++;
            }

            else                           // no empty frames available. replaceemnt necessary
            {
                 min=0;
                 for (  j = 0; j < f; j++)
                 {
                     if (count[min] > count[j])           // finding the element with least recent use from count array
                     {
                         min=j;
                     }
                     m[min]=rs[i];
                     count[min]=next;
                     next++;
                     
                 }
                 
            }
            
            pf++;
        }

        for (  j = 0; j < f; j++)                       // printing the present state of frame
       {
         printf("\t%d",m[j]);
       }
    
        if (flag[i]==0)                                // printing the pf if pf occcurs
        {
        printf("\tPf no :%d",pf);
        }

        printf("\n");
        
        
    }
     

    printf("The total no page faults is:%d",pf);
    

}