#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
  for(int i=1; i<5; i++)
  {
        pid_t pid = fork();
	char name;


	if(pid == 0)
	{
		printf("Enter your name: ");
		scanf("%s", &name);
		printf("The child name is %s\n", &name);
	}
	else if(pid > 0)
	{
		wait(NULL);
		printf("Job is done\n");
	}
	else
	{
		printf("error404");
	}
  }
  return 0;
}
