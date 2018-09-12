#include<stdio.h>
void main()
{
    int n,i,items[25],cur,seek=0;
    printf("Enter the number of items:");
    scanf("%d",&n);
    printf("\nEnter the items:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&items[i]);
    }
    printf("\n Enter the current position of the disk read head:");
    scanf("%d",&cur);

     //FCFS

    for(i=0;i<n;i++)
    {
        if(items[i]>cur)
        {
            seek+=items[i]-cur;
                      
        }
        else
        {
            seek+=cur-items[i];
        }
        cur=items[i];

    }

    printf("\n Seek time for FCFS=%d\n",seek);


}