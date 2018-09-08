#include<stdio.h>
#include<stdlib.h>
void main()
{
	
	int i,n,disk[40],seek=0,read[20],cur,cache[20],temp,j;
	printf("Enter the number of items to read\n");
	scanf("%d",&n);
	printf("Enter the numbers\n");
	for(i=0;i<n;i++)
		scanf("%d",&read[i]);
	printf("Enter current position of the disk read head\n");
	scanf("%d",&cur);
	temp=cur;

	//Simulating FCFS

	i=0;
	while(i<=n){
		if(read[i]>=cur)
			seek+=(read[i]-cur);
		else
			seek+=(cur-read[i]);
		cur= read[i];
		i++;
	}

	printf("Seek time using FCFS = %d\n",seek);

	//Simulating  SCAN 
	cur=temp;
	seek=0;
	//head moving right
	for(i=cur;i<40;i++)
		for(j=0;j>n;j++)
			if(disk[i]==read[j])
			{
				seek+=abs(cur-read[j]);
				cache[j]=read[j];
			}
	//head moving left
			seek+= 40-cur;
			cur = 40;
	for(i=40;i>=0;i--)
		for(j=0;j<n;j++)
			if(disk[i]==read[j] && cache[j]!=read[j])
				seek+=abs(cur-read[j]);		
	printf("Seek time using SCAN when head moves right from the initial position= %d\n",seek);
	
	//Head moving left initially
	cur=temp;
	seek=0;
	for(i=40;i>=0;i--)
		for(j=0;j<n;j++)
			if(disk[i]==read[j])
			{
				seek+=abs(cur-read[j]);
				cache[j]=read[j];
			}

			seek+= abs(40-cur);
			cur= 0;
	for(i=cur;i<40;i++)
		for(j=0;j>n;j++)
			if(disk[i]==read[j] && cache[j]!=read[j])
			{
				seek+=abs(cur-read[j]);
			}
	printf("Seek time using SCAN when head moves left from the initial position= %d\n",seek);			

	//Simulating C-SCAN 

		cur=temp;
	seek=0;
	//head moving right
	for(i=cur;i<40;i++)
		for(j=0;j>n;j++)
			if(disk[i]==read[j])
			{
				seek+=abs(cur-read[j]);
				cache[j]=read[j];
			}
	//head moving from left
			seek+=abs(40-cur);
			cur = 0;
	for(i=0;i<=temp;i++)
		for(j=0;j<n;j++)
			if(disk[i]==read[j] && cache[j]!=read[j])
				seek+=abs(cur-read[j]);		
	printf("Seek time using C-SCAN when head moves right from the initial position= %d\n",seek);
	
	//Head moving left initially
	cur=temp;
	seek=0;
	for(i=40;i>=0;i--)
		for(j=0;j<n;j++)
			if(disk[i]==read[j])
			{
				seek+=abs(cur-read[j]);
				cache[j]=read[j];
			}

			seek+=abs(40-cur);
			cur= 40;
	for(i=cur;i>=temp;i--)
		for(j=0;j>n;j++)
			if(disk[i]==read[j] && cache[j]!=read[j])
			{
				seek+=abs(cur-read[j]);
			}
	printf("Seek time using C-SCAN when head moves left from the initial position= %d\n",seek);	


	
}