// Authors: Joey Lewis & Jeongsu Shin
// Date: 5/7/24
// Purpose: Final Project

#include <stdio.h>
#define STRING_CAP 100
#define MAX_ROWS 100
#define MAX_COLUMNS 100

int mainMenu();
void loadImage(char fileName[], int image[MAX_ROWS][MAX_COLUMNS], int *rows, int *cols);
void displayImage(int rows, int cols, int image[MAX_ROWS][MAX_COLUMNS]);
int editMenu();
void cropImage(int rows, int cols, int image[MAX_ROWS][MAX_COLUMNS]);
void dimImage(int rows, int cols, int image[MAX_ROWS][MAX_COLUMNS]);
void brightenImage(int rows, int cols, int image[MAX_ROWS][MAX_COLUMNS]);

int main(){
	int mainMenuChoice, editMenuChoice;
	char saveFileChoice;	
	char fileName[STRING_CAP]; 
	int image[MAX_ROWS][MAX_COLUMNS]; 
	int rows = 0, cols = 0;
	
	do{
		mainMenuChoice = mainMenu();
		if(mainMenuChoice == 1){
			printf("File name to import from: ");
			scanf(" %s", fileName);
			
			loadImage(fileName, image, &rows, &cols);
			
			printf("\nSuccessfully loaded!\n\n");
			
		}
		else if(mainMenuChoice == 2){
			displayImage(rows, cols, image);
		}
		else if(mainMenuChoice == 3){
			do {
				printf("\n");
				editMenuChoice = editMenu();
				if(editMenuChoice == 1){
					cropImage(rows, cols, image);										
				}
				else if(editMenuChoice == 2){
					dimImage(rows, cols, image);
				}
				else if(editMenuChoice == 3){
					brightenImage(rows, cols, image);
				}
				else if(editMenuChoice == 0){
					printf("\n");
				}
				else {
					printf("Invalid option, please try again.\n");
				}
			} while (editMenuChoice != 1 && editMenuChoice != 2 && editMenuChoice != 3 && editMenuChoice != 0);
		}
		else if (mainMenuChoice == 0){
			printf("\nGoodbye!\n\n");
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

void loadImage(char fileName[], int image[MAX_ROWS][MAX_COLUMNS], int *rows, int *cols){
	char imageArray[MAX_COLUMNS+1];
	
	FILE* rptr;
	rptr = fopen(fileName, "r");
	
	if (rptr == NULL){
		printf("Can't open file\n");
		return ;
	}
	
	int row = 0;
	while(fgets(imageArray, MAX_COLUMNS, rptr) != NULL){
		int col = 0;
		for(int i=0; imageArray[i] != '\0'; i++){
			if(imageArray[i] >= '0' && imageArray[i] <= '4'){
				image[row][col++] = imageArray[i] - '0'; 	
			}
		}
		if(col>*cols){
			*cols = col;
		}
		row++;
		
	}
	*rows = row;
		
	fclose(rptr);
}

void displayImage(int rows, int cols, int image[MAX_ROWS][MAX_COLUMNS]){
	printf("\n");
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			switch(image[i][j]){
			case 0 :
				printf(" ");
				break;
			case 1 :
				printf(".");
				break;
			case 2 :
				printf("o");
				break;
			case 3 :
				printf("O");
				break;
			case 4 :
				printf("0");
				break;
			default:
				printf(" ");
				break;
			}
		}
		printf("\n");
	}
	printf("\n");
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

void cropImage(int rows, int cols, int image[MAX_ROWS][MAX_COLUMNS]){
	printf("\n");
	printf(" 1");
	for(int i = 1; i < cols +1; i++){
		printf(" ");
	}
	printf("%d\n", cols);
	
	for(int i=0; i<rows; i++){
		if (i == 0){
			printf("1 ");
		}
		else {
			printf("  ");
		}
		for(int j=0; j<cols; j++){
			switch(image[i][j]){
			case 0 :
				printf(" ");
				break;
			case 1 :
				printf(".");
				break;
			case 2 :
				printf("o");
				break;
			case 3 :
				printf("O");
				break;
			case 4 :
				printf("0");
				break;
			default:
				printf(" ");
				break;
			}
		}
		printf("\n");
	}
	
	printf("%d", rows);
	printf("\n");
	printf("The image you want to crop is %d x %d\n", rows, cols);
	printf("The row and column values start in the upper lefthand corner.\n\n");
	
	int leftCol, rightCol, topRow, bottomRow;
	printf("Which column do you want to be the new left side? ");
	scanf("%d", &leftCol);
	printf("Which column do you want to be the new right side? ");
	scanf("%d", &rightCol);
	printf("Which row do you want to be the new top? ");
	scanf("%d", &topRow);
	printf("Which row do you want to be the new bottom? ");
	scanf("%d", &bottomRow);
	
	for(int i = topRow - 1; i <= bottomRow; i++){
		for(int j = leftCol - 1; j <= rightCol; j++){
			switch(image[i][j]){
			case 0 :
				printf(" ");
				break;
			case 1 :
				printf(".");
				break;
			case 2 :
				printf("o");
				break;
			case 3 :
				printf("O");
				break;
			case 4 :
				printf("0");
				break;
			default:
				printf(" ");
				break;
			}
		}
		printf("\n");
	}
	
	char fileName[STRING_CAP], saveFileChoice;
	printf("Would you like to save the file? (y/n) \n");
	scanf(" %c", &saveFileChoice);
	
	if (saveFileChoice == 'y'){
		printf("What do you want to name the image file? (include the extension)\n");
		scanf(" %s", fileName);
		
		FILE* wptr;
		wptr = fopen(fileName, "w");
		
		if (wptr == NULL){
			printf("Can't open file\n");
			return ;
		}
		
		for (int i = topRow - 1; i <= bottomRow; i++){
			for (int k = leftCol - 1; k <= rightCol; k++){
				if (image[i][k] < 4){
					fprintf(wptr, "%d", image[i][k] + 1); 
				}
				else {
					fprintf(wptr, "%d", image[i][k]);
				}
			}
			fprintf(wptr, "\n"); 
		}				
		fclose(wptr);
	}	
}

void dimImage(int rows, int cols, int image[MAX_ROWS][MAX_COLUMNS]){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			switch(image[i][j]){
			case 0 :
				printf(" ");
				break;
			case 1 :
				printf(" ");
				break;
			case 2 :
				printf(".");
				break;
			case 3 :
				printf("o");
				break;
			case 4 :
				printf("O");
				break;
			default:
				printf(" ");
				break;
			}
		}
		printf("\n");
	}
	char fileName[STRING_CAP], saveFileChoice;
	printf("Would you like to save the file? (y/n) \n");
	scanf(" %c", &saveFileChoice);
	if (saveFileChoice == 'y'){
		printf("What do you want to name the image file? (include the extension)\n");
		scanf(" %s", fileName);
		
		FILE* wptr;
		wptr = fopen(fileName, "w");
		
		if (wptr == NULL){
			printf("Can't open file\n");
			return ;
		}
		
		for (int i = 0; i < rows; i++){
			for (int k = 0; k < cols; k++){
				if (image[i][k] > 0){
					fprintf(wptr, "%d", image[i][k] - 1); 
				}
				else {
					fprintf(wptr, "%d", image[i][k]);
				}
			}
			fprintf(wptr, "\n"); 
		}		
		fclose(wptr);
	}
}

void brightenImage(int rows, int cols, int image[MAX_ROWS][MAX_COLUMNS]){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			switch(image[i][j]){
			case 0 :
				printf(".");
				break;
			case 1 :
				printf("o");
				break;
			case 2 :
				printf("O");
				break;
			case 3 :
				printf("0");
				break;
			case 4 :
				printf("0");
				break;
			default:
				printf(" ");
				break;
			}
		}
		printf("\n");
	}
	char fileName[STRING_CAP], saveFileChoice;
	printf("Would you like to save the file? (y/n) \n");
	scanf(" %c", &saveFileChoice);
	if (saveFileChoice == 'y'){
		printf("What do you want to name the image file? (include the extension)\n");
		scanf(" %s", fileName);
		
		FILE* wptr;
		wptr = fopen(fileName, "w");
		
		if (wptr == NULL){
			printf("Can't open file\n");
			return ;
		}
		
		for (int i = 0; i < rows; i++){
			for (int k = 0; k < cols; k++){
				if (image[i][k] < 4){
					fprintf(wptr, "%d", image[i][k] + 1); 
				}
				else {
					fprintf(wptr, "%d", image[i][k]);
				}
			}
			fprintf(wptr, "\n"); 
		}				
		fclose(wptr);
	}	
}

