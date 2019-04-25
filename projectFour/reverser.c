#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "stack.h"

int main(int argc, const char * argv[]) {
    int opt;
    char inputFile[100];
    char outputFile[100];

    struct Stack *stack = createStack(100);

    //get command line args
    while((opt = getopt(argc, argv, "hio:")) != -1) {
        switch(opt) {
            case 'h':
                printf("You need help!");
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
    FILE *fp = fopen(inputFile, "r");
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);
    buffer = malloc((size + 1) * sizeof(*buffer));
    fread(buffer, size, 1, fp);
    buffer[size] = '\0';
    
    char *pch;
    pch = strtok(buffer, " ");
    while(pch != NULL) {
        printf("%s\n", pch);
        //check stack for duplicates
        int item = atoi(pch);
        if(!duplicate(stack, item)) {
            push(stack, item);
        }
        pch = strtok(NULL, " ");
    }
    fclose(fp);
    
    //write to file
    fp = fopen(outputFile, "w");
    fprintf(fp, "%d", pop(stack));
    fclose(fp);
    
    return 0;
}
