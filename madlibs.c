//Authors: Gabriel Markovetski,  Leah Kinne, and Collin Bible
//Date: 12/6/2024
//Project:

#include <stdio.h>


#define MADLIB1 "madlib1.txt"
#define MADLIB2 "madlib2.txt"
#define ROWS 50
#define COLS 50


int readFile(FILE* fptr, int rows, int cols, char words[][cols]);
void wordType(int rows, int cols, char words[][cols], char prompts[]);
void removeEnd (int rows, int cols, char words[][cols]);
void displayStory(int rows, int cols, char words[][cols], char prompts[]);

int main() {
	FILE* fptr;
	char words[ROWS][COLS];
	char prompts[ROWS]; // used to mark the rows that require a space to be added.
	int rows = ROWS;

	fptr = fopen(MADLIB2, "r");

	if(fptr == NULL){
		printf("Failed to open madlib file.\n");
		return 0;
	}
	
	rows = readFile(fptr, ROWS, COLS, words);
	fclose(fptr);
	wordType(rows, COLS, words, prompts);
	removeEnd(rows, COLS, words);
	displayStory(rows, COLS, words, prompts);
	printf("\n");

	return 0;
}

/*
	This function keeps track of the number of lines in the file and updating the rows variable, this also reads the
	file and puts it into the 2d array words
*/
int readFile(FILE* fptr, int rows, int cols, char words[][cols]){
	int lineCount = 0;

	while(lineCount < rows && fgets(words[lineCount], cols, fptr) != NULL){
		lineCount++;
	}
	return lineCount;
}


/*
	When the COLS size is too small to hold a ful line,
	we get multiple rows that should not have a space added to them.
	Use 'prompts' and 'lastPrompt' to mark the rows that need a space added.
*/
void wordType(int rows, int cols, char words[][cols], char prompts[]){
	int lastPrompt = 0;
	for(int i = 0; i < rows; i++){
		prompts[i] = lastPrompt;
		if (words[i][1] == '\n' || words[i][1] == '\0'){
			prompts[i] = 1;
			switch(words[i][0]){
			case 'A':
				printf("Please enter an adjective: ");
				scanf("%s", words[i]);
				break;
			case 'N':
				printf("Please enter a noun: ");
				scanf("%s", words[i]);
				break;
			case 'V':
				printf("Please enter a verb: ");
				scanf("%s", words[i]);
				break;
			}
			lastPrompt = 1;
		}
		else {
			lastPrompt = 0;
		}
	}
}

/*
	This function finds all the '\n' characters in the 2d array, and if there is a null character right after the '\n', then
	it is replaced witha null character
*/
void removeEnd (int rows, int cols, char words[][cols]){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols && words[i][j] != '\0'; j++){
			if(words[i][j] == '\n'){
				if (words[i][j+1] == '\0'){
					words[i][j] = '\0';
					break;
				}
				else{
					words[i][j] = ' ';
				}
			}
		}
	}
}

/*
	This functions checks if there are any terminator characters (periods, commas, etc) and returns 0 if true and a 1 if false
*/
int isAlphabet(char c)
{
	static char check[] = ".,?!\"\'";
	for (int i=0; check[i] != 0; i++){
		if (check[i] == c){
			return 0;
		}
	}
	return 1;
}

/*
	This function uses the function above and prompts to make sure there is a space added where it is needed while also printing
	out the rest of the story
*/
void displayStory(int rows, int cols, char words[][cols], char prompts[]){
	for(int i = 0; i < rows; i++){
		if (prompts[i] && isAlphabet(words[i][0])) {
			printf(" ");
		}
		printf("%s", words[i]);	
	}
}


