#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[]) {
	int opt;
    	char inputFile[100] = "input.txt";
    	char outputFile[100] = "output.txt";

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
    
    	//read from file
    	char *buffer = NULL;
    	size_t size = 0;
    	FILE *fp1 = fopen(inputFile, "r");
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
    	fclose(fp1);
    
    	//write to file
    	FILE *fp2 = fopen(outputFile, "w");
	for(int i = 0; i < count; i++) {
		fprintf(fp2, "%d\n", pop(stack));
    	}
	fclose(fp2);
    	
	return 0;
}
