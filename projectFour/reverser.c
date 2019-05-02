#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[]) {
	int opt;
    	char inputFile[100];
    	char outputFile[100];

    	struct Stack *stack = createStack(100);

    	//get command line args
    	while((opt = getopt(argc, argv, "hi:o:")) != -1) {
        	switch(opt) {
            	case 'h':
                	printf("Usage -i <input file> -o <output file> -h <help>\n");
			exit(0);
                	break;
            	case 'i':
                	strncpy(inputFile, optarg, 100);
                	break;
            	case 'o':
                	strncpy(outputFile, optarg, 100);
                	break;
        	}	
    	}	

	//default file setup
	if(strcmp(inputFile, "") == 0) {
		strncpy(inputFile, "input.txt", 10);
	}
	if(strcmp(outputFile, "") == 0) {
		strncpy(outputFile, "output.txt", 11);
	}
    
    	//read from file
    	char *buffer = NULL;
    	size_t size = 0;
    	FILE *fp1 = fopen(inputFile, "r");
	if(!fp1) { 
		printf("Input File Does Not Exist!\n");
		exit(0);
	}
    	fseek(fp1, 0, SEEK_END);
    	size = ftell(fp1);
    	rewind(fp1);
    	buffer = malloc((size + 1) * sizeof(*buffer));
    	fread(buffer, size, 1, fp1);
    	buffer[size] = '\0';

    	char *pch;
    	pch = strtok(buffer, " \n");
	int count = 0;
	while(pch != NULL) {
        	//check stack for duplicates
        	int item = atoi(pch);
        	if(!duplicate(stack, item)) {
            		push(stack, item);
			count++;
        	}
        	pch = strtok(NULL, " \n");
    	}	
    	
    
    	//write to file
    	FILE *fp2 = fopen(outputFile, "w");
	if(!fp2) {
		printf("Error Writing To Output File!");
		exit(0);
	}
	for(int i = 0; i < count; i++) {
		fprintf(fp2, "%d\n", pop(stack));
    	}

	//fclose(fp1);
	//fclose(fp2);
    	
	return 0;
}
