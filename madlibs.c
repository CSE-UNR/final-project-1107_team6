//Authors: Gabriel Markovetski,  Leah Kinne, and Collin Bible
//Date: 12/6/2024
//Project:

#include <stdio.h>


#define MADLIB1 "madlib1.txt"
#define MADLIB2 "madlib2.txt"
#define ROWS 100
#define COLS 20


void readFile(FILE* fptr, int rows, int cols, char words[][cols]);
void wordType(int rows, int cols, char words[][cols]);
void removeEnd (int rows, int cols, char words[][cols]);
void displayStory(int rows, int cols, char words[][cols]);

int main() {
FILE* fptr;
char words[ROWS][COLS];


fptr = fopen(MADLIB2, "r");

if(fptr == NULL){
printf("Failed to open madlib file.\n");
return 0;
}
readFile(fptr, ROWS, COLS, words);
fclose(fptr);
//wordType(ROWS, COLS, words);
removeEnd(ROWS, COLS, words);
displayStory(ROWS, COLS, words);
printf("\n");


return 0;
}

/*
void fileChoice(){

if(num == 1){
*
}
else{

}

}

*/
void readFile(FILE* fptr, int rows, int cols, char words[][cols]){
int linecount = 0;

while(linecount < rows && fgets(words[linecount], cols, fptr) != NULL){
linecount++;
}
}

/*
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
*/
/*
void checkForCaseSensitivity(words[][]){
char
if(words == 'A' && words != 'a'){
return 1;
}
else if(words == 'N' && words != 'n'){
return 2;
}
else if(words == 'V' && words != 'v'){
return 3;
}
else{
return 4;
}
}
*/

void wordType(int rows, int cols, char words[][cols]){
for(int i = 0; i < rows; i++){
for(int j = 0; j < cols; j++){
words[i][j];
/* if(words[i][j] == 'A' && words[i][j] != 'a'){
words[i][j] = 1;
}
else if(words[i][j] == 'N' && words[i][j] != 'n'){
words[i][j] = 2;
}
else if(words[i][j] == 'V' && words[i][j] != 'v'){
words[i][j] = 3;
} */
switch(words[i][j]){
case 'A':
printf("Please enter an adjective: ");
scanf("%s", &words[i][j]);
break;
case 'N':
printf("Please enter a noun: ");
scanf("%s", &words[i][j]);
break;
case 'V':
printf("Please enter a verb: ");
scanf("%s", &words[i][j]);
break;

}
}
}

}


void removeEnd (int rows, int cols, char words[][cols]){
for(int i = 0; i < rows; i++){
for(int j = 0; words[i][j] != '\0'; j++){
if(words[i][j] == '\n'){
words[i][j] = ' ';
}
}
}
}


void displayStory(int rows, int cols, char words[][cols]){
for(int i = 0; i < rows; i++){
for(int j = 0; j < cols; j++){
printf("%c", words[i][j]);
}
}

}









