//
//  main.c
//  ArrayCopy
//
//  Created by Francisco Lira on 9/16/20.
//  Copyright © 2020 Francisco Lira. All rights reserved.
//
#include<stdio.h>
#include<string.h>

void printArr(int *a, int size, char *name){
    //Your code here
    int i;
    printf("printArr:");
    for (i = 0; i < size; i++)
    {
        printf(" %d", *(a + i));
    }
    printf("\n");
}

int* arrCopy(int *a, int size){
    //Your code here
    int i;
      int *CopyOfArray = (int *) malloc(sizeof(int) * size);
      for (i = 0; i < size; ++i) {
          *(CopyOfArray + i) = *(a + i);
      }
      return CopyOfArray;
}

int main(){
    int f;
    int *arr;
    int *array_copy;
    int i;
    printf("Enter the size of array: ");
    scanf("%d", &f);

    //Dynamically create an int array of n items
    //Your code here
     arr = (int *) malloc(sizeof(int) * f);
    //Ask user to input c
    for (i = 0; i < f; i++) {
        printf("Enter array content #%d: ", i+1);
        scanf("%d", arr+i);
    }
    //Your code here
    
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
    
    //Print original array
    printArr(arr, f, "Original");

    //Copy array
    array_copy = arrCopy(arr, f);

    //Print new array
    printArr(array_copy, f, "Copied");

    printf("\n");

    return 0;
}
