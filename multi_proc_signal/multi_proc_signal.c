#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>

int conc_amnt;
pid_t pid[100];

void pa_handle_sigint(int signal)
{
	printf("[pid](%d): SIGINT is handled in pa_handle_sigint()\n", getpid());
	printf("[pid](%d): [func](exit)  with [conc_amnt](%d)\n", getpid(),conc_amnt);
	exit(0);
}

void pa_handle_sigchld(int signal)
{
	printf("[pid](%d): SIGINT is handled in pa_handle_sigchld()\n", getpid());
	pid_t pid;
	int status;
	while ((pid = waitpid(-1,&status,WNOHANG)) > 0) {

		conc_amnt--;
		printf("[pid](%d): [cpid](%d) is waited in pa_handle_sigchld()\n", getpid(), pid);
	}
	
}

int main (int argc, char * argv[])
{
	conc_amnt = argv[2][0] - 48;
	printf("[pid](%d): start\n", getpid());
	
	struct sigaction act;
	memset(&act,0,sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_handler=pa_handle_sigint;
	sigaction(SIGINT, &act, NULL);

	struct sigaction act1;
	memset(&act1,0,sizeof(act1));
	sigemptyset(&act1.sa_mask);
	act1.sa_handler=pa_handle_sigchld;
	sigaction(SIGCHLD, &act1, NULL);
	for (int i = 0; i < conc_amnt - 1; i++) {
		pid[i] = fork();
		if (pid[i] == 0) {
			printf("[pid](%d): start\n", getpid());
			pause();
		}
	}

	sleep(1);
	for (int i = 0; i < conc_amnt - 1; i++) {
		kill(pid[i], 2);
	}

	while (conc_amnt != 1) {
		printf("[pid](%d): [func](pause) with [conc_amnt](%d)\n", getpid(), conc_amnt);
		pause();
	}
	pause();
	return 0;
}
