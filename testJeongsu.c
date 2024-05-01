#include <stdio.h>

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


void displayImage(int row, int col, char imageArray[][col]){
	
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%c", imageArray[i][j]);
		}
	}
}


