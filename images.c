// Authors: Joey Lewis, Jeongsu Shin
// Date: 5/7/24
// Purpose: 

int mainMenu();

int main(){
	int mainMenuChoice, mainMenuPtr;	
	
	do {
		mainMenuChoice = mainMenu();
		
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
