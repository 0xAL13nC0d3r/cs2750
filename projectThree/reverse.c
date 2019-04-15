#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	//Part A
	for(int i = argc - 1; i > 0; i--) {
		printf("%s ", argv[i]);
	}

	printf("\n");


	//Part B
	char *min = argv[1];
	char *max = argv[1];

	for(int i = 1; i < argc; i++) {
		//get min	
		if(strcmp(min, argv[i]) > 0) {
			min = argv[i];
		}
		
		//get max
		if(strcmp(max, argv[i]) < 0) {
			max = argv[i];
		}	
	}

	printf("The smallest string was: %s\n", min);
	printf("The largest string was: %s\n", max);

	return 0;
}
