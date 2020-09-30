//
//  main.c
//  Averages
//
//  Created by Francisco Lira on 9/9/20.
//  Copyright © 2020 Francisco Lira. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int Pos = 0; //I used this Variable to store the sum of positive numbers.
    int Neg = 0 ;//I used this variable to store the sum of negative numbers.
    int PosCount = 0 ;// PosCount is to store count of positive numbers. If PosCount is 0, then no positive numbers entered.
    int NegCount = 0 ;// I used NegCount to store count of negative numbers. If NegCount is 0 then no negative numbers entered.
    int i = 1;
    
    while(i != 0)//this while-loop runs until 0 is entered.
   
    {
        printf("Please enter an integer: ");
        scanf("%d",&i);// Makes User Input a Number
        
        if(i < 0)//If Input Number is a negative number, then it will be stored with the Negatives.
        {
            Neg = Neg + i;//This serves to find sum.
            NegCount++;
        }
        else if(0 < i)// If Input Number is a positive number, then it will be stored with the Positives.
        {
            Pos = Pos + i;//This serves to find sum.
            PosCount++;
        }
    }
    //This part of the code will print the results.
    printf("\n");
    if(PosCount != 0)
    {
        printf("Positive average: %d\n",Pos/PosCount);
    }
    if(NegCount != 0)
        printf("Negative average: %d\n",Neg/NegCount);
    
    return 0;
    }
