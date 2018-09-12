#include<stdio.h>
void main()
{
    int n,i,items[25],j,swap=0,cur,seek=0,beg=0,flag=0;
    printf("Enter the number of items:");
    scanf("%d",&n);
    printf("\nEnter the items(0-100):\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&items[i]);
    }
    printf("\n Enter the current position of the disk read head:");
    scanf("%d",&cur);

    //Sorting items using Bubble Sort
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(items[j]>items[j+1])
            {
                swap=items[j];
                items[j]=items[j+1];
                items[j+1]=swap;
            }
        }
    }
    

    //SCAN
    for(i=0;i<n && flag==0;i++)
    {
        if(items[i]==cur)
        {
            beg=i;
            flag=1;
        }
        else if(items[i]>cur)
        {
            beg=i;
            flag=1;
        }
        else if(i==n-1 && flag==0)
        {
            beg=n;
        }
    }
    printf("\n the order of scanning is\n");

    for(i=beg;i<n;i++)
    {
        seek+=items[i]-cur;
        cur=items[i];
        printf(" %d ",items[i]);
    }
    cur=0;
    if(beg>0)
    {
        for(i=0;i<beg;i++)
        {
            seek+=items[i]-cur;
            cur=items[i];
            printf(" %d ",items[i]);
        }
    } 

    printf("\n Seek time for CSCAN=%d\n",seek);


}