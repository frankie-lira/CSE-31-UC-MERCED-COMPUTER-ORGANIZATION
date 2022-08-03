//
//  main.c
//  MatrixMult
//
//  Created by Francisco Lira on 9/24/20.
//

#include <stdio.h>
#include <stdlib.h>

int** matMult(int **a, int **b, int size){
    // (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
    
    int i;
    int j;
    int k;
    int temp;
    int** MultArr;
   
    MultArr = (int**) malloc(size*sizeof(int*));  //Create a array of 1D
    
    for (i = 0; i < size; i++) //This command creates memory for each element

    *(MultArr + i) = (int *)malloc(size * sizeof(int)); //previously used: res[i] = (int*) malloc(size * sizeof(int));
    
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            temp = 0;
            for(k = 0; k < size; k++){
                temp = temp + ((*(*(a + i) + k)) * (*(*(b + k) + j)));
            }
            *(*(MultArr + i) + j) = temp;
        }
    }
    return MultArr;
}

void printArray(int **arr, int n, int l){
    // (2) Implement your printArray function here
    int i, j;
    
    printf("\nMatrix %d", l);
    printf(":");
    printf("\n\n");
   
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf(" %d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int n = 0,i,j;
    int f = 1;
    int g = 2;
    int h = 3;
    int **matA, **matB, **matC;
    
    //(1) Define 2 n x n arrays (matrices).
    printf("\nEnter a value for n to create a matrix with the form of n x n: ");
    scanf("%d", &n);
    
    matA = (int**) malloc(n*sizeof(int*)); //First matrix/array
    for (i = 0; i < n; i++)
    *(matA + i) = (int *)malloc(n * sizeof(int));
//    Previously used: matA[i] = (int*) malloc(n * sizeof(int));
    
    matB = (int**) malloc(n * sizeof(int*)); //Second matrix/array
    for (i = 0; i < n; i++)
    *(matB + i) = (int *)malloc(n * sizeof(int));
//    Previously used: matB[i] = (int*) malloc(n * sizeof(int));
    
    matC = (int**) malloc(n * sizeof(int*)); //Third matrix/array
    for (i = 0; i < n; i++)
    *(matC + i) = (int *)malloc(n * sizeof(int));
//   Previously used:  matC[i] = (int*) malloc(n * sizeof(int));
    
    printf("Enter %d value/s for the first matrix: ", (n * n));
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", (*(matA + i) + j));
        }
    }

    printf("Enter %d value/s for the second matrix: ", (n * n));
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
        scanf("%d", (*(matB + i) + j));
        }
    }

    //(3) Call printArray to print out the 2 arrays here.
    printArray(matA, n, f); //Printing arrays
    printArray(matB, n, g);
    
    
    //(5) Call matMult to multiply the 2 arrays here.
    matC = matMult(matA, matB, n); //Matrix multiplication
    
    //(6) Call printArray to print out resulting array here.
    printArray(matC, n, h);
    
    return 0;
}
