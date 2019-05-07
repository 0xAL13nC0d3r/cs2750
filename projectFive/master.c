#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[]) {
	int opt;
	int value;
	key_t key = 9999;
	int shmid;	
	char *shm;
	char *s;

	while((opt = getopt(argc, argv, "hn:")) != -1) {
		switch(opt) {
		case 'h':
			printf("Usage -n <integer>\n");
			exit(0);
			break;
		case 'n':
			value = atoi(optarg);
			break;	
		
		}
	}

	
	//create shared memory
	if((shmid = shmget(key, sizeof(value), 0644 | IPC_CREAT)) == -1) {
		printf("Error creating memory segment!\n");
		exit(1);
	}

	shm = shmat(shmid, NULL, 0);
	if(shm == (char *) -1) {
		printf("Error attaching to memory segment!\n");
		exit(1);
	}
		
	//set location to zero
	s = shm;
	*s = 0;

	//create new process 
	if(fork() == 0) {
		//execv("./worker 	
	}
	


}
