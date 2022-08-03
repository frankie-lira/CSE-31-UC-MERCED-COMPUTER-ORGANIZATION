//
//  wordsearch.c
//  wordsearch
//
//  Created by Francisco Lira on 10/25/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);
int searchHorizL(char** arr, int n, char* word);
int searchHorizR(char** arr, int n, char* word);
int searchVertDwn(char** arr, int n, char* word);
int searchDiagLR(char** arr, int n, char* word);
int searchDiagRL(char** arr, int n, char* word);
char listCompare(char* word, int letter);
char lowerCase(char** arr, int letter, int i, int j);
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
    for(i = 0; i < bSize; i++) {
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
    for(i = 0; i < 50; i++) {
        *(words+i) = (char*)malloc(20 * sizeof(char));
        fgets(*(words+i), 20, fptr);
    }
    
    // Remove newline characters from each word (except for the last word)
    for(i = 0; i < 49; i++) {
        *(*(words+i) + strlen(*(words+i))-2) = '\0';
    }
    
    // Print out word list
    printf("Printing list of words:\n");
    for(i = 0; i < 50; i++) {
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

void printPuzzle(char** arr, int n) {
    // This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
    // Your implementation here
    int i, j;
    
    for(i = 0; i < n; i++){
        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(*(arr+i)), *(*(arr+i)+1), *(*(arr+i)+2), *(*(arr+i)+3), *(*(arr+i)+4), *(*(arr+i)+5), *(*(arr+i)+6), *(*(arr+i)+7), *(*(arr+i)+8), *(*(arr+i)+9), *(*(arr+i)+10), *(*(arr+i)+11), *(*(arr+i)+12), *(*(arr+i)+13), *(*(arr+i)+14));
    }

}

void searchPuzzle(char** arr, int n, char** list, int listSize) {
    // This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
    // Your implementation here
    int i;
    for(i = 0; i < listSize; i++){
        if (searchHorizL(arr, n, *(list + i))){
            printf("Word found: %s\n", *(list + i));
        }
        if (searchHorizR(arr, n, *(list + i))){
            printf("Word found: %s\n", *(list + i));
        }
        if (searchVertDwn(arr, n, *(list + i))){
            printf("Word found: %s\n", *(list + i));
        }
        if (searchDiagLR(arr, n, *(list + i))){
            printf("Word found: %s\n", *(list + i));
        }
        if (searchDiagRL(arr, n, *(list + i))){
            printf("Word found: %s\n", *(list + i));
        }
    }
}
    

int searchHorizL(char** arr, int n, char* word){
    int i, j, size = strlen(word);
    
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n - size; j++){
            int letter = 0;
            while(letter < size){
                char x = listCompare(word, letter);
                char y = lowerCase(arr, letter, i, j);
            if(x == y){
                if(letter == size - 1){
                    return 1;
                }
            }
            else{
                break;
            }
            letter++;
        }
    }
}
    return 0;
}

int searchHorizR(char** arr, int n, char* word){
    int i, j, size = strlen(word);
    for(i = 0; i < n; i++){
        for(j = n - 1; j >= size; j--){
                int letter = 0;
            while(letter < size){
                    char x = listCompare(word, letter);
                    char y = lowerCase(arr, letter, i, j);
                if(x == y){
                    if(letter == size - 1){
                        return 1;
                    }
                }
                else{
                    break;
                }
                letter++;
            }
        }
    }
        return 0;
    }

int searchVertDwn(char** arr, int n, char* word){
    int i, j;
    int size = strlen(word);
    for(i = 0; i < n; i++){
        for(j = 0; j < n-size; j++){
                int letter = 0;
            while(letter < size){
                char x = listCompare(word, letter);
                char y = lowerCase(arr, letter, i, j);
            if(x == y){
                if(letter == size - 1){
                    return 1;
                    }
                }
                else{
                    break;
                }
                letter++;
            }
        }
    }
    return 0;
}

int searchDiagLR(char** arr, int n, char* word){
    int i, j, size = strlen(word);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            int letter = 0;
            while(letter < size && (i + letter < n) && (j + letter < n)){
                char x = listCompare(word, letter);
                char y = lowerCase(arr, letter, i, j);
            if(x == y){
                if(letter == size - 1){
                    return 1;
                }
            }
            else{
                break;
            }
            letter++;
        }
    }
}
    return 0;
}

int searchDiagRL(char** arr, int n, char* word){
    int i, j, size = strlen(word);
    
    for(i = 0; i < n; i++){
        for(j = n - 1; j > 0; j--){
            int letter = 0;
            while(letter < size && (i + letter < n) && (j + letter < n)){
                char x = listCompare(word, letter);
                char y = lowerCase(arr, letter, i, j);
                
            if(x == y){
                if(letter == size - 1){
                    return 1;
                }
            }
            else{
                break;
            }
            letter++;
        }
    }
}
    return 0;
}


    char listCompare(char* word, int letter){
        char temp;
        
        if(*(word + letter) >= 'A' && *(word + letter) <= 'Z'){
            temp = *(word + letter);
        }
        else{
            temp = *(word + letter) - 32;
        }
        return temp;
    }

char lowerCase(char** arr, int letter, int i, int j){
    char temp;
    
            if(*(*(arr+i)+j+letter) >= 'A' && *(*(arr+i)+j+letter) <= 'Z'){
                temp = *(*(arr+i)+j+letter);
            } else{
                temp = *(*(arr+i)+j+letter) - 32;
            }
            return temp;
}
