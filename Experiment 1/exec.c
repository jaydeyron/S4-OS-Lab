#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	char *c[]={"/home/s4csbs/task.out",NULL};
	execv(c[0], c);
    perror("execv");
    exit(EXIT_FAILURE);
    printf("exec failed\n");
	return 0;
}
/*//TASK.OUT
#include<stdio.h>

int main(){
	printf("Inside task\n");
}*/
