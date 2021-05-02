#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char name;

void childTask()
{
  printf("Enter your name: ");
  scanf("%s", &name);
  printf("The child name is %s\n", &name);
}

int main(void)
{
  for(int i=1; i<5; i++)
  {
        pid_t pid = fork();


	if(pid == 0)
	{
		childTask();
		exit(EXIT_SUCCESS);
	}
	else if(pid > 0)
	{
		wait(NULL);
	}
	else
	{
		printf("error404");
	}
  }
  printf("Job is done!\n");
  return EXIT_SUCCESS;
}
