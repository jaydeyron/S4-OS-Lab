#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
void child()
{
	printf("Inside child \n");
	
}
void parent()
{
	printf("Inside parent \n");
	
}
int main()
{
	pid_t pid=fork();
	printf("PID : %d \t",pid);
	if(pid==0)
	{
		child();
		exit(EXIT_SUCCESS);
	}
	else if(pid>0)
	{
		parent();
	}
	else
	{
		printf("Unable to create \n");
	}
	return EXIT_SUCCESS;
}
