//
//  NodeStruct.c
//  NodeStruct
//
//  Created by Francisco Lira on 9/17/20.
//  Copyright © 2020 Francisco Lira. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
    
    
    printf("Address of head is:%p",&head);
    printf("\nValue of Head is:%d",head);
    printf("\nAddress of IValue is:%p",&head->iValue);
    printf("\nAddress of FValue is:%p",&head->fValue);
    printf("\nAddress of Next is:%p",&head->next);
   
    
    
    return 0;
}
