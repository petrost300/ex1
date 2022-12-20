#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	
	FILE *fp;
	int number;
	char filename[100];
	
	printf("Enter the number of processes you want to create and the file: ");
	
	scanf("%d" "%s", &number, filename);
	fp = fopen(filename,"w");
	fprintf(fp,"Parent pid -> %d\n", getppid());
	
	for (int i=0;i<number;i++)
	{
	
		if (fork() == 0) 
		{
			fprintf(fp,"child pid -> %d\n", getpid());
			exit(0);
		}
		wait(NULL);
	}
	
	
}
