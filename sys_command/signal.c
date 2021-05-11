#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(int argc ,char * argv[]) {
	key_t key[5] = {1,2,3,4,5};
	int sem_id[5];
	for (int i = 0; i < 5; i++) {
		sem_id[i] = semget(key[i],1,IPC_CREAT);
		semctl(sem_id[i], 1, SETVAL);
	}

	
	

	
	return 0;
}
