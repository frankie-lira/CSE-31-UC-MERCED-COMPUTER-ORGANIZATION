//
//  pointers.c
//  pointer
//
//  Created by Francisco Lira on 9/10/20.
//  Copyright © 2020 Francisco Lira. All rights reserved.
//

#include "pointers.h"
#include <stdio.h>

int main()
{
int x = 0, y = 0, *px, *py;
int arr[10];
    
    for (int i = 0; i < 10; i++){
        arr[i] = i;
    }
    printf(" %d, %d, %d \n", x, y, arr[0]);
    printf("The address of x is: %p \n", &x);
    printf("The address of y is: %p \n", &y);
    px= &x;
    py= &y;
    printf("px = %p, address of px = %p \n", px, &px);
    printf("py = %p, address of py = %p \n", py, &py);
    for (int i = 0; i < 10; i++){
        printf("Content of %d element is: %d arr+i is %p \n", i, *(arr+i), arr+i);
    }
    printf("arr %p, address of arr[0] %p \n", arr, &arr[0]);
    printf("Address of arr is %p", &arr);
    printf("\n");
   
    return 0;
}
