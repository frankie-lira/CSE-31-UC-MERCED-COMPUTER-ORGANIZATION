#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>            //new change

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);


bool findright(char** arr, int n, char* word, int posx, int posy);
bool findup(char** arr, int n, char* word, int posx, int posy);
bool finddown(char** arr, int n, char* word, int posx, int posy);
bool findbl_tr(char** arr, int n, char* word, int posx, int posy);
bool findtl_br(char** arr, int n, char* word, int posx, int posy);


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
       *(*(words+i) + strlen(*(words+i))-1) = '\0';
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
   int i;
   for(i=0;i<n;i++)
   {
   printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(*(arr+i)), *(*(arr+i)+1), *(*(arr+i)+2), *(*(arr+i)+3), *(*(arr+i)+4), *(*(arr+i)+5), *(*(arr+i)+6), *(*(arr+i)+7), *(*(arr+i)+8), *(*(arr+i)+9), *(*(arr+i)+10), *(*(arr+i)+11), *(*(arr+i)+12), *(*(arr+i)+13), *(*(arr+i)+14) );
   }

}

void searchPuzzle(char** arr, int n, char** list, int listSize){
   // This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
   // Your implementation here

bool foundright = false;
bool foundup = false;
bool founddown = false;
bool foundbl_tr = false;
bool foundtl_br = false;

int i,j,wno,c;

for(wno=0;wno<50;wno++)
{
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
      
          if( tolower(*(*(arr+i)+j)) == tolower(*(*(list+wno))) )          //new change
          {
           foundright = findright(arr,n,*(list+wno),i,j);
           foundup = findup(arr,n,*(list+wno),i,j);
           founddown = finddown(arr,n,*(list+wno),i,j);
           foundbl_tr = findbl_tr(arr,n,*(list+wno),i,j);
           foundtl_br = findtl_br(arr,n,*(list+wno),i,j);
          }
          if(foundright)
          {
           c=0;
           while( *(*(list+wno)+c) )
           {
               *(*(arr + i) + j+c ) = tolower( *(*(arr + i) + j+c ) );   //new change
               c++;
           }
           foundright = false;
          }

          if(foundup)
          {
           c=0;
           while( *(*(list+wno)+c) )
           {
               *(*(arr + i-c) + j) = tolower( *(*(arr + i-c) + j) );     //new change
               c++;
           }
           foundup = false;
          }

          if(founddown)
          {
           c=0;
           while( *(*(list+wno)+c) )
           {
               *(*(arr + i+c) + j) = tolower( *(*(arr + i+c) + j) );     //new change
               c++;
           }
           founddown = false;
          }

          if(foundtl_br)
          {
           c=0;
           while( *(*(list+wno)+c) )
           {
               *(*(arr + i+c) + j+c) = tolower( *(*(arr + i+c) + j+c) );   //new change
               c++;
           }
           foundtl_br = false;
          }

          if(foundbl_tr)
          {
           c=0;
           while( *(*(list+wno)+c) )
           {
               *(*(arr + i-c) + j+c) = tolower(*(*(arr + i-c) + j+c)); //new change
               c++;
           }
           foundbl_tr = false;
          }

       }
   }

}
}

bool findright(char** arr, int n, char* word, int posx, int posy)
{
   int c=1;
   while( *(word+c) )
   {
       if(posy+c >= n)
       {
           return false;
       }
       else
       {
           if( tolower( *(*(arr+posx)+posy+c) ) == tolower( *(word+c) ) )    //new change
           {
               c++;
           }
           else
           {
               return false;
           }
       }
   }
   return true;

}

bool findup(char** arr, int n, char* word, int posx, int posy)
{
   int c=1;
   while( *(word+c) )
   {
       if(posx-c < 0)
       {
           return false;
       }
       else
       {
           if( tolower( *(*(arr+posx-c)+posy) ) == tolower( *(word+c) ) )    //new change
           {
               c++;
           }
           else
           {
               return false;
           }
       }
  
   }
   return true;

}

bool finddown(char** arr, int n, char* word, int posx, int posy)
{
   int c=1;
   while( *(word+c) )
   {
       if(posx+c >= n)
       {
           return false;
       }
       else
       {
           if( tolower( *(*(arr+posx+c)+posy) ) == tolower( *(word+c) ) )    //new change
           {
               c++;
           }
           else
           {
               return false;
           }
       }
   }
   return true;
}


bool findbl_tr(char** arr, int n, char* word, int posx, int posy)
{
   int c=1;
   while( *(word+c) )
   {
       if(posx-c < 0 || posy+c >=n)
       {
           return false;
       }
       else
       {
           if( tolower(*(*(arr+posx-c)+posy+c)) == tolower(*(word+c) ) )    //new change
           {
               c++;
           }
           else
           {
               return false;
           }
       }
      
   }
   return true;

}

bool findtl_br(char** arr, int n, char* word, int posx, int posy)
{
   int c=1;
   while( *(word+c) )
   {
       if(posx+c >= n || posy+c >=n)
       {
           return false;
       }
       else
       {
           if( tolower(*(*(arr+posx+c)+posy+c)) == tolower(*(word+c) ) )   //new change
           {
               c++;
           }
           else
           {
               return false;
           }
       }
   }
   return true;

}
