#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x35353535

int isPrime(int n);
int getPrime(int n);

int main(int argc, char *argv[]) {
	int prime, value, shmid, reset;
	char *s, *shm;
	
	if(argc < 2) { 
		printf("Missing argument! Usage <./worker <Integer>\n");
		exit(1);
 	}
	
	//find largest prime smaller than input value
	value = atoi(argv[1]);
	printf("Worker: finding largest prime smaller than %d...\n", value);
	prime = getPrime(value);	
	
	//get shared memory id
	shmid = shmget(SHM_KEY, sizeof(value), 0);
	if(shmid == -1) {
		printf("Worker: unable to get memory ID.\n");
		exit(1);
	}
	
	//attach to shared memory
	shm = shmat(shmid, NULL, 0);
	if(shm == (char *) - 1) {
		printf("Worker: error attaching to memory.\n");
		exit(1);
	}
	
	//insert value into shared memory
	s = shm;
	if(*s != 0) {
		printf("Worker: shared memory location is zero.\n");
		exit(1);
	} else {
		printf("Worker: shared memory location is zero.\n");		
		printf("Worker: putting %d into shared memory.\n", prime);
		*s = prime;
		printf("Worker: process terminating.\n");
		exit(0);	
	}	
}

int isPrime(int n) {
	int flag = 0;
	for(int i = 2; i <= (n / 2); i++) {
		if(n % i == 0) {
			flag = 1;
			break;
		}
	}
	
	if(n == 1) { 
		return 0; 
	} else {
		if(flag == 0) {
			return 1;
		} else {
			return 0;
		}
	}
		
	return 0;
	
}

int getPrime(int n) {
	int mainPrime = 2;
	for(int i = 2; i <= n; i++) {
		if(isPrime(i)) {
			if(i > mainPrime) {
				mainPrime = i;
			}
		}
	}
	return mainPrime;
}
