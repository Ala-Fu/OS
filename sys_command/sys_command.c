#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	if (argc != 2) {
		exit(1);
	}

	if ((dp = opendir(argv[1])) == NULL) {
		exit(1);
	}

	while ((dirp = readdir(dp)) != NULL) {
		printf("%ld %s\n", dirp->d_ino, dirp->d_name);
	}

	closedir(dp);
	exit(0);

	return 0;
}
