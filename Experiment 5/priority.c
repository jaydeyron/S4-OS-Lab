#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

struct process
{
	int pid;
	int at;
	int wt;
	int tat;
	int bt;
	int priority;
	int ct;
	int pos;
	int rt;
} p[20], temp;

int n, tq;
float avwt, avtat;

void display()
{
	int i;
	printf("Process ID\tArrival Time\tBurst Time\tPriority\tCompletion time\tTurnaround Time\tWaiting Time\n");
	for(i = 0; i < n; i++)
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].tat, p[i].wt);
	printf("\nAverage Waiting Time: %f", avwt);
	printf("\nAverage Turnaround Time: %f\n", avtat);
}

void swap(int i, int j)
{
	temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void atSort()
{
	int i, j;
	for(i = 0; i < n - 1; i++)
		for(j = 0; j < n - i - 1; j++)
			if(p[j].at > p[j + 1].at)
				swap(j, j + 1);
}

void pidSort()
{
	int i, j;
	for(i = 0; i < n - 1; i++)
		for(j = 0; j < n - i - 1; j++)
			if(p[j].pid > p[j + 1].pid)
				swap(j, j + 1);
}

void priorSort()
{
	int i, j;
	for(i = 0; i < n - 1; i++)
		for(j = 0; j < n - i - 1; j++)
			if(p[j].priority > p[j + 1].priority)    
				swap(j, j + 1);
}

void priority()
{
	int i, j, pct, highest, loc, f, flag = 0;
	for(i = 0; i < n; i++)
		if(p[i].at > 0)
			flag = 1;

	if(flag == 1)
		atSort();
	else
		priorSort();

	p[0].ct = p[0].at + p[0].bt;
	p[0].tat = p[0].ct - p[0].at;
	p[0].wt = p[0].tat - p[0].bt;

	avtat = p[0].tat;
	avwt = p[0].wt;

	for(i = 1; i < n; i++)
	{
		pct = p[i - 1].ct;
		highest = 20;
		f = 0;

		for(j = i; j < n; j++)
		{
			if(p[j].at <= pct && p[j].priority < highest)
			{
				f = 1;
				loc = j;
				highest = p[j].priority;
			}

			if(f == 0)
			{
				if(p[j].at >= pct && p[j].priority < highest)
				{
					loc = j;
					highest = p[j].priority;
				}
			}
		}

		if(f == 1)
			p[loc].ct = pct + p[loc].bt;
		else
			p[loc].ct = p[loc].at + p[loc].bt;

		p[loc].tat = p[loc].ct - p[loc].at;
		p[loc].wt = p[loc].tat - p[loc].bt;

		swap(loc, i);

		avtat += p[i].tat;
		avwt += p[i].wt;
	}

	avtat /= n;
	avwt /= n;

	pidSort();
	printf("\nPriority Scheduling:\n");
	display();
}

void main()
{
	int i;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		p[i].pid = i;
		printf("Enter the Arrival Time of process %d: ", i );
		scanf("%d", &p[i].at);
		printf("Enter the Burst Time of process %d: ", i );
		scanf("%d", &p[i].bt);
		printf("Enter the Priority of process %d: ", i );
		scanf("%d", &p[i].priority);
	}
	priority();
}
