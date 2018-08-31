#include<stdio.h>

void findturn(int n,int wait[],int burst[],int turn[]){
	int i;
	printf("Process   Waiting Time   Burst Time   Turnaround Time \n");
	for(i=0;i<n;i++){
		turn[i]=burst[i]+turn[i];
		printf("%d         %d               %d               %d \n",i+1,wait[i],burst[i],turn[i]);
	}
}
void findwait(int n,int wait[],int burst[],int turn[]){
	int i;
	wait[0]=0;
	for(i=1;i<n;i++)
		wait[i]=burst[i-1]+wait[i-1];
	findturn(n,wait,burst,turn);
}

void main()
{
	int i,n,wait[10],burst[10],turn[10];
	printf("Enter the number of processes \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time of process %d \n",i+1);
		scanf("%d",&burst[i]);
	}
	findwait(n,wait,burst,turn);
}