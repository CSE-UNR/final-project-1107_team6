//Gabriel Markovetski,  Leah Kinne, and Collin Bible
//12/6/2024

#include <stdio.h>

#define madlib1 "madlib1.txt"
#define madlib2 "madlib2.txt"
#define madlibComplete "madlibComplete.txt"

#define ROW 100
#define COL 20
#define WORDS 30

void wordType (FILE *mad1, FILE *mad2, int wordCountType[], int whichMadLib);
void getMadLibWords(int wordCountType[], char madLibWords[][COL]);

int main() {
	FILE *mad1;
	FILE *mad2;
	FILE *madC;
	int wordCountType [WORDS];
	int whichMadLib = 0;
	char madLibWords[ROW][COL];
	
	printf("Do you want madlib one or madlib two (1 or 2): \n");
	scanf("%d", &whichMadLib);
	
	 wordType (mad1, mad2, wordCountType, whichMadLib);
	 getMadLibWords(wordCountType, madLibWords);
	 
	 for(int i=0; i<ROW && wordCountType[i-1] != 0; i++){
		for(int j=0; j<COL && madLibWords[i][j] != '\0'; j++){
			printf("%c", madLibWords[i][j]);
		}
	 }
return 0;
}


void wordType (FILE *mad1, FILE *mad2, int wordCountType [], int whichMadLib) {
	int index = 0;
	char C;
	
	if(whichMadLib == 1)
	{
		mad1 = fopen(madlib1, "r");
		if(mad1 == NULL){
			printf("could not open madlib1 file.\n");
		}
		for(int i = 0; !feof(mad1); i++) {
			fscanf(mad1, "%c", &C);
			switch(C) {
				case 'A': 
					wordCountType [index] = 1;
					index++;
					break;
				case 'N':
					wordCountType [index] = 2;
					index++;
					break;
				case 'V':
					wordCountType [index] = 3;
					index++;
					break;
				default:
					break;
			}
		
		}
		
		fclose(mad1);
	}
	else
	{
		mad2 = fopen(madlib2, "r");
		if(mad2 == NULL){
			printf("could not open madlib2 file.\n");
		}
		for(int i = 0; !feof(mad2); i++) {
			fscanf(mad2, "%c", &C);
			switch(C) {
				case 'A': 
					wordCountType [index] = 1;
					index++;
					break;
				case 'N':
					wordCountType [index] = 2;
					index++;
					break;
				case 'V':
					wordCountType [index] = 3;
					index++;
					break;
				default:
					break;
			}
		
		}
		
		fclose(mad2);
	}	
}

void getMadLibWords(int wordCountType[], char madLibWords[][COL]) {
	int index = 0;
	while(index < ROW && wordCountType[index] != 0) {
		switch (wordCountType[index]) {
			case 1:
				printf("Please enter an adjective: ");
				scanf("%s", &madLibWords[index][COL]);
				break;
			case 2:
				printf("Please enter a noun: ");
				scanf("%s", &madLibWords[index][COL]);
				break;
			case 3:
				printf("Please enter a verb: ");
				scanf("%s", &madLibWords[index][COL]);
				break;
			default:
				break;
		}
		index++;
	}

}

