  #include<stdio.h>
  void main()
  {
    int i,j,k,pf=0,count=0,rs[25],m[25],n,f;
    printf("Enter the length of reference string:");
    scanf("%d",&n);
    printf("\nEnter the reference strimg:");
    for (  i = 0; i < n; i++)
    {
         scanf("%d",&rs[i]);
    }
    printf("\nEnter the no of frames:");
    scanf("%d",&f);
    for (  i = 0; i < f; i++)
    {
         m[i]=-1;                  //indicating the of frmes are empty
    }
    printf("\nThe page replacement process is\n");
    for (  i = 0; i < n; i++)       //iterating the rs loop
    {
         for (  k = 0; k < f; k++)           //iterating the frame loop
         {
             if (m[i]==rs[i])                //checking if each element in rs is already present in one of the frames
             {
                 break;                      //if present break the loop -hit
             }
             
         }
         
         if (k==f)                           // if  the rs is not found then it is added to the next available frame -miss
         {
           m[count]=rs[i];                   //next available frame indicated by count
           count++;
           pf++;                            // the no of page faults is incremented
         }
         for(j=0;j<f;j++)
         {
          printf("\t%d",m[j]);                                 //the state of frames is printed  after each iteraton
         }
         if (k==f)
         {
           printf("\tPage fault no:%d",pf);
         }
         printf("\n");
         if (count==f)
         {
           count=0;
         }

         
         
    }
    printf("The total no of page faults is %d",pf);

    
  }