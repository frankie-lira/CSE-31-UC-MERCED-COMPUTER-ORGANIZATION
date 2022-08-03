//
//  wordsearch.c
//  wordsearch
//
//  Created by Francisco Lira on 10/25/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// DO NOT INCLUDE OTHER LIBRARY!

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);
int HorizontalRight(char** arr, int n, char* word);
int HorizontalLeft(char** arr, int n, char* word);
int VerticalDown(char** arr, int n, char* word);
int DiagonalRightDown(char** arr, int n, char* word);
int DiagonalLeftDown(char** arr, int n, char* word);
char listUpperCase(char* word, int index);
char matrixUpperCase(char** arr, int index, int i, int j, int type);
void matrixlowerCase(char** arr, int wordSize, int row, int col, int direction);

// Main function, DO NOT MODIFY!!!
int main(int argc, char **argv) {
    int bSize = 15;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
    char **words = (char**)malloc(50 * sizeof(char*));

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read puzzle block into 2D arrays
    for(i=0; i<bSize; i++){
        *(block+i) = (char*)malloc(bSize * sizeof(char));

        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), *(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5, *(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, *(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
    fclose(fptr);

    // Open file for reading word list
    fptr = fopen("states.txt", "r");
    if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }
    
    // Save words into arrays
    for(i=0; i<50; i++){
        *(words+i) = (char*)malloc(20 * sizeof(char));
        fgets(*(words+i), 20, fptr);
    }
    
    // Remove newline characters from each word (except for the last word)
    for(i=0; i<49; i++){
        *(*(words+i) + strlen(*(words+i))-2) = '\0';
    }
    
    // Print out word list
    printf("Printing list of words:\n");
    for(i=0; i<50; i++){
        printf("%s\n", *(words + i));
    }
    printf("\n");
    
    // Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
    printf("\n");

    // Call searchPuzzle to find all words in the puzzle
    searchPuzzle(block, bSize, words, 50);
    printf("\n");
    
    // Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
    printf("\n");
    
    return 0;
}

void printPuzzle(char** arr, int n){
    // This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
    // Your implementation here
    for(int i=0; i<n; i++) {
        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(*(arr+i)), *(*(arr+i)+1), *(*(arr+i)+2), *(*(arr+i)+3), *(*(arr+i)+4), *(*(arr+i)+5), *(*(arr+i)+6), *(*(arr+i)+7), *(*(arr+i)+8), *(*(arr+i)+9), *(*(arr+i)+10), *(*(arr+i)+11), *(*(arr+i)+12), *(*(arr+i)+13), *(*(arr+i)+14));
   }
}

void searchPuzzle(char** arr, int n, char** list, int listSize){
    // This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
    // Your implementation here
    
    //Goes through the list of 50 words
    for(int i=0; i<listSize; i++){
        if(HorizontalRight(arr, n, *(list+i))){
            printf("Word found: %s\n", *(list+i));
        }
        if(HorizontalLeft(arr, n, *(list+i))){
            printf("Word found: %s\n", *(list+i));
        }
        if(VerticalDown(arr, n, *(list+i))){
            printf("Word found: %s\n", *(list+i));
        }
        if(DiagonalRightDown(arr, n, *(list+i))){
            printf("Word found: %s\n", *(list+i));
        }
        if(DiagonalLeftDown(arr, n, *(list+i))){
            printf("Word found: %s\n", *(list+i));
        }
    }
}

//This Function is to search horizontally from left to right
int HorizontalRight(char** arr, int n, char* word){
    //Used to get the length of word on list (e.g. California = 10 letters)
    int size = strlen(word);
  
    for(int i=0; i<n; i++){
        for(int j=0; j<n-size; j++){
            //the Index is used to go through letter by letter of the word
            //Loops as long as index is less than the length of the word
            int index = 0;
            while(index<size){
                //Created two char variables to compare char of arr and word (temporarily makes lowercase)
                //This was used to not overlap other lowercase functions
                char x = listUpperCase(word, index);
                char y = matrixUpperCase(arr, index, i, j, 1);
               
                //If char of a and b match consistently through while-loop => Found a word
                if(x == y){
                    //But also checks if index is the same size as the word
                    if(index == size-1){
                        //Calls the function to make char lowercase in the matrix
                        matrixlowerCase(arr, size, i, j, 1);
                        return 1;
                    }
                }
                else{
                    break;
                }
                index++;
            }
        }
    }
    return 0;
}

//Function to search horizontally from right to left
int HorizontalLeft(char** arr, int n, char* word){
    int size = strlen(word);
  
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=size-1; j--){
            int index = 0;
            while(index<size){
               char x = listUpperCase(word, index);
               char y = matrixUpperCase(arr, index, i, j, 2);
                
               if(x == y){
                   if(index == size-1){
                       matrixlowerCase(arr, size, i, j, 2);
                       return 1;
                   }
               }
               else{
                   break;
               }
                index++;
            }
        }
    }
    return 0;
}

//Function to search vertically from top to bottom
int VerticalDown(char** arr, int n, char* word){
    int size = strlen(word);

    for(int i=0; i<n; i++){
        for(int j=0; j<n-size; j++){
            int index = 0;
            while(index<size){
                char x = listUpperCase(word, index);
                char y = matrixUpperCase(arr, index, i, j, 3);
               
                if(x == y){
                    if(index == size-1){
                        matrixlowerCase(arr, size, j, i, 3);
                        return 1;
                    }
                }
                else{
                    break;
                }
                index++;
            }
        }
    }
    return 0;
}


//Function to search diagonally from top left to bottom right
int DiagonalRightDown(char** arr, int n, char* word){
    int size = strlen(word);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int index = 0;
            while(index<size && (i + index < n) && (j + index < n)){
                char x = listUpperCase(word, index);
                char y = matrixUpperCase(arr, index, i, j, 4);
               
                if(x == y){
                    if(index == size-1){
                        matrixlowerCase(arr, size, i, j, 4);
                        return 1;
                    }
                }
                else{
                    break;
                }
                index++;
            }
        }
    }
    return 0;
}


//Function to search diagonally from top right to bottom left
int DiagonalLeftDown(char** arr, int n, char* word){
    int size = strlen(word);
    
    for(int i=0; i<n; i++){
        for(int j=n-1; j>0; j--){
            int index = 0;
            while(index<size && (i+index<n) && (j+index<n)){
                char x = listUpperCase(word, index);
                char y = matrixUpperCase(arr, index, i, j, 5);
               
                if(x == y){
                    if(index == size-1){
                        matrixlowerCase(arr, size, i, j, 5);
                        return 1;
                    }
                }
                else{
                    break;
                }
                index++;
            }
        }
    }
    return 0;
}


//Function to make letters of the word lowercase
char listUpperCase(char* word, int index){
    char temp;
    
    if(*(word+index) >= 'A' && *(word+index) <= 'Z'){
        temp = *(word+index);
    }
    else{
        temp = *(word+index) - 32;
    }
    return temp;
}

//Function to temporarily make letters in matrix lowercase
//This is used to be able to compare with the letters from the list of states
char matrixUpperCase(char** arr, int index, int i, int j, int type){
    char temp;
    
    switch(type){
        case 1:
            if(*(*(arr+i)+j+index) >= 'A' && *(*(arr+i)+j+index) <= 'Z'){
                temp = *(*(arr+i)+j+index);
            } else{
                temp = *(*(arr+i)+j+index) - 32;
            }
            return temp;
            break;
        case 2:
            if(*(*(arr+i)+j-index) >= 'A' && *(*(arr+i)+j-index) <= 'Z'){
                temp = *(*(arr+i)+j-index);
            } else{
                temp = *(*(arr+i)+j-index) - 32;
            }
            return temp;
            break;
        case 3:
            if(*(*(arr+j+index)+i) >= 'A' && *(*(arr+j+index)+i) <= 'Z'){
                temp = *(*(arr+j+index)+i);
            } else{
                temp = *(*(arr+j+index)+i) - 32;
            }
            return temp;
            break;
        case 4:
            if(*(*(arr+i+index)+j+index) >= 'A' && *(*(arr+i+index)+j+index) <= 'Z'){
                temp = *(*(arr+i+index)+j+index);
            } else{
                temp = *(*(arr+i+index)+j+index) - 32;
            }
            return temp;
            break;
        case 5:
            if(*(*(arr+i+index)+j-index) >= 'A' && *(*(arr+i+index)+j-index) <= 'Z'){
                temp = *(*(arr+i+index)+j-index);
            } else{
                temp = *(*(arr+i+index)+j-index) - 32;
            }
    }
    return temp;
}


//Function that makes the letters in the matrix lowercase "permanently"
void matrixlowerCase(char** arr, int wordSize, int row, int col, int direction){
   switch(direction){
       case 1: //horizontal left to right
           for(int i=col; i<col+wordSize; i++){
               if(*(*(arr+row)+i) >= 'A' && *(*(arr+row)+i) <= 'Z'){
                   *(*(arr+row)+i) += 32;
               }
           }
           break;
       case 2:   //horizontal right to left
           for(int i=col; i>col-wordSize; i--){
               if(*(*(arr+row)+i) >= 'A' && *(*(arr+row)+i) <= 'Z'){
                   *(*(arr+row)+i) += 32;
               }
           }
           break;
       case 3:   //vertical top to bottom
           for(int i=row; i<row+wordSize; i++){
               if(*(*(arr+i)+col) >= 'A' && *(*(arr+i)+col) <= 'Z'){
                   *(*(arr+i)+col) += 32;
               }
           }
           break;
       case 4:   //diagonal topleft to bottomright
           for(int i=0;i<wordSize;i++){
               if(*(*(arr+row+i)+col+i) >= 'A' && *(*(arr+row+i)+col+i) <= 'Z'){
                   *(*(arr+row+i)+col+i) += 32;
               }
           }
           break;
        case 5: //diagonal top right to bottom left
           for(int i=wordSize; i>0; i--){
               if(*(*(arr+row+i)+col+i) >= 'A' && *(*(arr+row+i)+col+i) <= 'Z'){
                   *(*(arr+row+i)+col+i) += 32;
               }
          }
     }
}
