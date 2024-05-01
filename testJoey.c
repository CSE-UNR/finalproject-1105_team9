#include <stdio.h>
#define STRING_CAP 100
#define FILE_NAME "image.txt"
void dimImage(int rows, int columns, char imageArray);
char getImage();
	
int main(){
		
/*	char fileName[STRING_CAP];
	printf("File name to import from: ");
	fgets(fileName, STRING_CAP, stdin); 
	printf("%s", fileName);
*/	
	int image[STRING_CAP];
	FILE* rptr;
	
	rptr = fopen(FILE_NAME, "r");
	
	if (rptr == NULL){
		printf("Can't open file\n");
	}
	int size = 0;
	for (int i = 0; i < 22; i++){
		fscanf(rptr, "%d", image[i]);
		printf("here\n");
		if (i = '\0'){
			size = i;
		}		
	}
	fclose(rptr);
	
	for (int i = 0; i < 21; i++){
		printf("%d", image[i]);
		printf("%d\n", i);
	}
	
}

void dimImage(int rows, int columns, char imageArray){
}
char getImage(){
	
	
}
