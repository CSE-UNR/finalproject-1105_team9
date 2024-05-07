#include <stdio.h>
#define STRING_CAP 100

int editMenu();
void displayImage();

int main(){
	editMenu();
	
	return 0;
}

int editMenu(){
	int editMenuChoice;

	printf("**EDITING**\n");
	printf("1: Crop image\n");
	printf("2: Dim image\n");
	printf("3: Brighten image\n");
	printf("0: Return to main menu\n");
	printf("\nChoose from one of the options above:");
	scanf(" %d", &editMenuChoice);
}

void loadImage(){
	char fileName[STRING_CAP];
	int image[STRING_CAP];
	
	printf("File name to import from: ");
	fgets(fileName, STRING_CAP, stdin); 
	printf("%s", fileName);
	
	FILE* rptr;
	
	rptr = fopen(fileName, "r");
	
	if (rptr == NULL){
		printf("Can't open file\n");
	}
	int size = 0;
	for (int i = 0; i < STRING_CAP; i++){
		fscanf(rptr, "%d", image);
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

void displayImage(int row, int col, char imageArray[][col]){
	
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%c", imageArray[i][j]);
		}
	}
}

void dimImage(){
}

void brightenImage(){
}


