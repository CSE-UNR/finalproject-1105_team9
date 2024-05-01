// Authors: Joey Lewis, Jeongsu Shin
// Date: 5/7/24
// Purpose: 

#include <stdio.h>
#define STRING_CAP 100

int mainMenu();
int editMenu();
void displayImage(int row, int col, char imageArray[][col]);

int main(){
	int mainMenuChoice, editMenuChoice, mainMenuPtr;	
	
	do {
		mainMenuChoice = mainMenu();
		if(mainMenuChoice == 1){
			
		}
		else if(mainMenuChoice == 2){
			displayImage(rows, collums, imageArray);
			printf("Display image\n");
		}
		else if(mainMenuChoice == 3){
			do {
				editMenuChoice = editMenu();
				
				if(editMenuChoice == 1){
					// crop image
				}
				else if(editMenuChoice == 2){
					// dim image
				}
				else if(editMenuChoice == 3){
					// brighten image
				}
				else if(editMenuChoice == 0){
				}
				else {
					printf("Invalid option, please try again.\n");
				}
			} while (editMenuChoice != 1 && editMenuChoice != 2 && editMenuChoice != 3 && editMenuChoice != 0);
		}
		else{
			printf("Wrong option! Please try again.\n");
		}
		
	} while(mainMenuChoice != 0);
	
	return 0;
}

int mainMenu(){
	int userInput;	
		printf("**ERINSTAGRAM**\n");
		printf("1: Load Image\n");
		printf("2: Display Image\n");
		printf("3: Edit Image\n");
		printf("0: Exit\n");
		printf("\nChoose from one of the options above: ");
		scanf("%d", &userInput);
	return userInput;
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
	return editMenuChoice;
}

void displayImage(int row, int col, char imageArray[STRING_CAP][STRING_CAP]){
	
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%c", imageArray[i][j]);
		}
	}
}

