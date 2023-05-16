#include <stdio.h>
#include <stdlib.h>
struct process{
		int pid;
		int at;
		int bt;
		int ct;
		int tat;
		int wt;
		}p[20],temp;
		
int n;
void asort()
{
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (p[i].at>p[j].at)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}
void fcfs()
{
	float sum1=0,sum2=0;
	p[0].ct=p[0].at+p[0].bt;
	for (int i=0;i<n;i++)
	{
		p[i+1].ct=p[i].ct+p[i+1].bt;
		p[i].tat=p[i].ct-p[i].at;
		sum1=sum1+p[i].tat;
		p[i].wt=p[i].tat-p[i].bt;
		sum2=sum2+p[i].wt;
	}
	printf("FCFS\n");
	printf("Processor ID\tArrival Time\t\t\tBurst Time\tCompletion Time\t\tTurn Around Time\tWaiting Time\n");
	for (int i=0;i<n;i++)
	{
		printf("\n%d \t\t\t",p[i].pid);
		printf("%d \t\t\t",p[i].at);
		printf("%d \t\t\t",p[i].bt);
		printf("%d \t\t\t",p[i].ct);
		printf("%d \t\t\t",p[i].tat);
		printf("%d \t\t\t",p[i].wt);
	}
	printf("\nAverage Turn Around Time : %f",sum1/n);
	printf("\nAverage Waiting Time : %f\n",sum2/n);
}

void main()
{
	printf("Enter The Number Of Processes : ");
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("\nEnter Processor ID : ");
		scanf("%d",&p[i].pid);
		printf("Enter Arrival Time : ");
		scanf("%d",&p[i].at);
		printf("Enter Burst Time : ");
		scanf("%d",&p[i].bt);
	}
	fcfs();
}
