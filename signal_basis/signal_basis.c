#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

void sigroutine(int signo)
{
	switch(signo)
	{
		case 10:
		printf("[pid](%d): [sig](SIGUSR1) is captured\n", getpid());
		break;

		case 12:
		printf("[pid](%d): [sig](SIGUSR2) is captured\n", getpid());
		break;

		case 2:
		printf("[pid](%d): [sig](SIGINT) is captured\n", getpid());
		printf("[pid](%d): exit\n", getpid());
		exit(0);

	}
}	

void signal_handler(int signal)
{
	switch(signal)
	{
		case 10:
		printf("[pid](%d): [sig](SIGUSR1) is captured\n", getpid());
		break;

		case 12:
		printf("[pid](%d): [sig](SIGUSR2) is captured\n", getpid());
		break;

		case 2:
		printf("[pid](%d): [sig](SIGINT) is captured\n", getpid());
		printf("[pid](%d): exit\n", getpid());
		exit(0);
	}
}

int main(int argc, char **argv)
{
	printf("[pid](%d): start\n", getpid());
	
	struct sigaction act;
	int ret = 0;

	act.sa_handler = signal_handler;
	
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGINT, &act, NULL);

	for (;;) {
		pause();
	}
	return 0;
}
