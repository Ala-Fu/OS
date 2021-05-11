#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
	fork();
	// First child runs program below
	fork();
	
	printf("Hello world\n");
	return 0;
}

/*int main(int argc, char *argv[])
{
	pid_t pid = 1;
	for (int i = 0; i < 2; i++) {
		if (pid != 0) {
			pid = fork();
		}
	}

	if (pid==0) { 
		printf("[pid](%d) [ppid](%d)\n",getpid(),getppid());
	} else {
		sleep(1);
		printf("[Initpid](%d)\n", getpid());
	}
	return 0;
}*/
