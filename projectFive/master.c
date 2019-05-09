#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x35353535

int main(int argc, char *argv[]) {	
	int wpid, opt, shmid, changed;
	int value = 100;
	char exec_value[100];	
	char *s, *shm;

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
	if((shmid = shmget(SHM_KEY, sizeof(value), 0644 | IPC_CREAT)) == -1) {
		printf("Master: error creating memory segment.\n");
		exit(1);
	}
	
	//attach to shared memory
	shm = shmat(shmid, NULL, 0);
	if(shm == (char *) -1) {
		printf("Master: error attaching to memory segment.\n");
		exit(1);
	}
		
	//set location to zero
	s = shm;
	*s = 0;

	//create new process
	printf("Master: creating child process...\n"); 
	int pid = fork();
	snprintf(exec_value, 100, "%d", value);
	if(pid == 0) {	
		execlp("./worker", "worker", exec_value, NULL);
	} 
	
	//wait for child process to end	
	wait(NULL);
	
	//end program
	printf("Master: process terminating.\n");
	exit(0);
	


	


}
