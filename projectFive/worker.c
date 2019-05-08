#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int isPrime(int n);
void getPrime(int n);

int main(int argc, char *argv[]) {
	if(argc < 2) { 
		printf("Missing argument! Usage <./worker> <Integer>\n");
		exit(1);
 	}
	int value = atoi(argv[1]);
	
	getPrime(value);	
	
	//check shared memory location
	int shmid;
	char *shm;
	char *s;

	shmid = shmget(9999, sizeof(value), 0644 | IPC_CREAT);	
	if(shmid < 0) {
		printf("Error getting memory!\n");
		exit(1);
	}
	
	shm = shmat(shmid, NULL, 0);
	if(shm == (char *) - 1) {
		printf("Error attaching to memory!\n");
		exit(1);
	}

	s = shm;
	printf("Location is %d", *s);


	
	
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

void getPrime(int n) {
	int mainPrime = 2;
	for(int i = 2; i <= n; i++) {
		if(isPrime(i)) {
			if(i > mainPrime) {
				mainPrime = i;
			}
		}
	}

	printf("Main prime is %d\n", mainPrime);
}
