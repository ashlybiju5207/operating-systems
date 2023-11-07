 #include<stdio.h>
 void main()
 {
    int n,r,i,j,alloc[100][100],max[100][100],avail[100],need[100][100];
    printf("\nEnter the noof proceses:");
    scanf("%d",&n);
    printf("\nEnter the noof resources:");
    scanf("%d",&r);
    printf("\nEnter the allocation matrix:");
    for ( i = 0; i < n; i++)
    {
         for (  j = 0; j < r; j++)
         {
             scanf("%d",&alloc[i][j]);
         }
         
    }
     printf("\nEnter the max matrix:");
    for ( i = 0; i < n; i++)
    {
         for (  j = 0; j < r; j++)
         {
             scanf("%d",&max[i][j]);
         }
         
    }
    printf("\nEnter the avilability matrix:");
    
    
         for (  j = 0; j < r; j++)
         {
             scanf("%d",&avail[j]);
         }
         printf("\nthe need matrix:");
    
    
          for (  i = 0; i < n; i++)
          {
             for (  j = 0; j < r; j++)
             {
                 need[i][j]=max[i][j]-alloc[i][j];
             }
             
          }
          for (  i = 0; i < n; i++)
          {
             for (  j = 0; j < r; j++)
             {
                  printf("%d",need[i][j]);
             }
             
          }
          
            int k=0,flag;
           int  finish[100],safeseq[100];
           for (  i = 0; i < n; i++)
           {
             finish[i]=0;
           }

           for (  i = 0; i < n; i++)
           {
            flag=0;
             if (finish[i]==0)
             {
                 for (  j = 0; j < r; j++)
                 {
                     if (need[i][j]>avail[j])
                     {
                         flag=1;
                         break;
                     }
                     
                 }
                 if (flag==0)
                 {
                     finish[i]=1;
                     safeseq[k]=i;
                     k++;

                      for ( j = 0; j < r; j++)
                      {
                         avail[j]+=alloc[i][j];
                      }
                      i=-1;
                      
                 }
                 
                 
             }
             
           }

           flag=0;
           for (  i = 0; i < n; i++)
           {
             if (flag==0)
             {
                 printf("\nThe system is in deadlock");
                 flag=1;
                 break;
             }
             
           }

           if (flag==0)
           {
             printf("\nThe system is in safe state:");
             printf("\nThe safesequence:");
             for (  i= 0; i < n; i++)
             {
                 printf("%d",safeseq[i]);
             }
             
           }
           
           
           
           
          
         
    
    

 }