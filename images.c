// Authors: Joey Lewis, Jeongsu Shin
// Date: 5/7/24
// Purpose: 

int mainMenu();
int editMenu();
void displayImage(int row, int col, char imageArray[][col]);

int main(){
	int mainMenuChoice, editMenuChoice, mainMenuPtr;	
	
	do {
		mainMenuChoice = mainMenu();
		if(mainMenuChoice == 1){
			displayImage();
		}
		else if(mainMenuChoice == 2){
		}
		else if(mainMenuChoice == 3){
			do{
				editMenuChoice = editMenu();
				if(editMenuChoice == 1){
				}
				else if(editMenuChoice == 2){
				}
				else if(editMenuChoice == 3){
				}
				else{
					printf("Wrong option! Please try again.\n");
				}
			} while(editMenuChoice != 0);
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
}

void displayImage(int row, int col, char imageArray[][col]){
	
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%c", imageArray[i][j]);
		}
	}
}

