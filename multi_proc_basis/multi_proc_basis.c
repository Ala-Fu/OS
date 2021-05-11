#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
	printf("[pid](%d) [ppid](%d): start\n", getpid(), getppid());
	int num_t = argv[2][0] - 48;
	
	char* path[2] = {"td1.txt", "td2.txt"};
	int fd1_td1 = open(path[0], O_RDONLY);
	printf("[pid](%d) [ppid](%d): [fd1_td1](%d) is got\n", getpid(), getppid(), fd1_td1);

	for (int i = 0; i < num_t - 1; i++)	
	{
		pid_t pid = fork();
		
		
		if (pid == 0)
		{
			printf("[pid](%d) [ppid](%d): start\n", getpid(), getppid());
			
			char *c = (char *) calloc(100, sizeof(char));
			int sz = read(fd1_td1, c, 5);
			c[sz] = '\0';
			printf("[pid](%d) [ppid](%d): [read](%s) by [fd1_td1](%d)\n", getpid(), getppid(), c, fd1_td1);
			
			int fd2_td1 = open(path[0], O_RDONLY);
			char *c1 = (char *) calloc(100, sizeof(char));
			printf("[pid](%d) [ppid](%d): [fd2_td1](%d) is got\n", getpid(), getppid(), fd2_td1);
			int sz1 = read(fd2_td1, c1, 5);
			c1[sz1] = '\0';
			printf("[pid](%d) [ppid](%d): [read](%s) by [fd2_td1](%d)\n", getpid(), getppid(), c1, fd2_td1);
			close(fd2_td1);
			close(fd1_td1);
			printf("[pid](%d) [ppid](%d): exit\n", getpid(), getppid());
			exit(0);
		}
	}
		if(1)
		{
			sleep(2);
			char *c1 = (char *) calloc(100, sizeof(char));
			int sz1 = read(fd1_td1, c1, 5);
			c1[sz1] = '\0';
			printf("[pid](%d) [ppid](%d): [read](%s) by [fd1_td1](%d)\n", getpid(), getppid(), c1, fd1_td1);
			
			close(fd1_td1);
			int fd1_td2 = open(path[1], O_RDONLY);
			printf("[pid](%d) [ppid](%d): [fd1_td2](%d) is got\n", getpid(), getppid(), fd1_td2);
			
			char *c2 = (char *) calloc(100, sizeof(char));
			int sz2 = read(fd1_td2, c2, 5);
			c2[sz2] = '\0';
			printf("[pid](%d) [ppid](%d): [read](%s) by [fd1_td2](%d)\n", getpid(), getppid(), c2, fd1_td2);
			close(fd1_td2);

			
			printf("[pid](%d) [ppid](%d): exit\n", getpid(), getppid());
			exit(0);	
		}
	return 0;
}






