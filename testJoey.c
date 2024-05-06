#include <stdio.h>
#define STRING_CAP 100
#define FILE_NAME "image.txt"

void dimImage(int rows, int columns, char imageArray);
char getImage();

	
int main(){
		
/*	
	// for get file name, use scanf so no blank space at the end from fgets
	char fileName[STRING_CAP];
	printf("File name to import from: ");
	fgets(fileName, STRING_CAP, stdin); 
	printf("%s", fileName);
*/	
	char image[STRING_CAP][STRING_CAP];
	FILE* rptr;
	
	rptr = fopen(FILE_NAME, "r");
	
	if (rptr == NULL){
		printf("Can't open file\n");
	}
	int size = 0;
//fscanf == 1, so if not true it will return 0 and stop outter loop
	int i = 0, k = 0;
	while (fscanf(rptr, " %c", &image[i][k]) == 1){
			
		printf("here, {i = %d}\n", i);
		
		for (k = 0; image[i][k] != '\n'; k++){
			fscanf(rptr, " %c", &image[i][k]);
		}
		i++;		
	}		
	
	fclose(rptr);
	
	for (int i = 0; i < 9; i++){
		printf("[i = %d]", i);
		for (int k = 0; k < 9; k++){
			
			printf("%c", image[i][k]);
			
		}
		printf("\n");
	}
	
}

void dimImage(int rows, int columns, char imageArray){
}
char getImage(){
	
	
}
