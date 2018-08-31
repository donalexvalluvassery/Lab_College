#include<stdio.h>
void findturn(int n,int wait[],int burst[],int turn[],int p[]){
	int i;
	printf("Process   Waiting Time   Burst Time   Turnaround Time \n");
	for(i=0;i<n;i++){
		turn[i]=burst[i]+wait[i];
		printf("%d         %d               %d               %d \n",p[i],wait[i],burst[i],turn[i]);
	}
}
void sort(int burst[],int n,int p[]){
	int i,j,temp,tempp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(burst[i]>burst[j]){
				tempp=p[i];
				p[i]=p[j];
				p[j]=tempp;
				temp=burst[i];
				burst[i]=burst[j];
				burst[j]=temp;
			}
		}
	}
}
void findwait(int n,int wait[],int burst[],int turn[],int p[]){
	int i;
	wait[0]=0;
	for(i=1;i<n;i++)
		wait[i]=burst[i-1]+wait[i-1];
	findturn(n,wait,burst,turn,p);
}

void main()
{
	int p[10],i,n,wait[10],burst[10],turn[10];
	printf("Enter the number of processes \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		printf("Enter the burst time of process %d \n",i+1);
		scanf("%d",&burst[i]);
	}
	sort(burst,n,p);
	findwait(n,wait,burst,turn,p);
}