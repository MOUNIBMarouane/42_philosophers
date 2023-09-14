#include "philo/main.h"

int main(int argc, char const *argv[])
{
	int pid;
	int	status;

	for (size_t j = 0; j < 2; j++)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("pid of child processe is : %d \n" , getpid());
			for (size_t i = 0; i < 3; i++)
			{
				printf("%d ", i);
				puts("");
				exit (1);
			}
		}
	}
	pid_t exited_prcesss = waitpid(-1, &status, 0);
	waitpid(exited_prcesss, NULL, 0);
	printf("exited prcess is :%d, and his sattus %d \n", exited_prcesss, status);
	return 0;
}
