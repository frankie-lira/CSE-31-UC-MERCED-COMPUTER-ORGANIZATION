#include <stdio.h>
#include <stdlib.h>

 int main() {
    int num;
    int *ptr;
    int **handle;

    num = 14;
    ptr = (int *)malloc(2 * sizeof(int)); //This is variable 1
    *ptr = num;
    handle = (int **)malloc(1 * sizeof(int *)); //This is variable 2
    *handle = ptr;

    // Insert extra code here
     printf("address of where the ptr is pointing: %p \n", ptr);
     printf("address of where the handle is pointing to: %p \n", handle);
     printf("The address of num is: %p \n", &num);
     
    return 0;
}

