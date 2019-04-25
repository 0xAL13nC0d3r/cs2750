#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
	//FILE *readFile;
	//readFile = fopen("sample.txt", "r");
	//char line[100];
	//fgets(line, 100, readFile);
	//printf("%s", line);
	
	//char str1;
	//str1 = fgetc(readFile);
	//while(str1 != EOF) {
	//	printf("%c", str1);
	//	str1 = fgetc(readFile);
	//}

	//printf("\n\n");

	//printf("%c", str1);
	//fclose(readFile);

	char *buffer = NULL;
	size_t size = 0;
	
	FILE *fp = fopen("sample.txt", "r");
	
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	rewind(fp);
	buffer = malloc((size + 1) * sizeof(*buffer));

	fread(buffer, size, 1, fp);

	buffer[size] = '\0';
	
	//printf("%s\n", buffer);

	char *pch;
	int i = 0;
	int someArray[100];
	pch = strtok(buffer, " ");
	while(pch != NULL) {
		printf("%s\n", pch);
		int a = atoi(pch);
		someArray[i] = a;
		i++;
		pch = strtok(NULL, " "); 
	}


	printf("Okay lets see our array!\n");
	for(int j = 0; j < i; j++) {
		printf("Number %d\n", someArray[j]);
	}
	
	return 0;

}
