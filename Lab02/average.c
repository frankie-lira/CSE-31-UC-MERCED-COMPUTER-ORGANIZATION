//
//  main.c
//  Average
//
//  Created by Francisco Lira on 9/15/20.
//  Copyright © 2020 Francisco Lira. All rights reserved.
//
#include <stdio.h>

/*
    Read a set of values from the user.
    Store the sum in the sum variable and return the number of values read.
*/
int read_values(double *sum) {
    int values=0,input=0;
    *sum = 0;
    printf("Enter input values (enter 0 to finish):\n");
    scanf("%d",&input);
    while(input != 0) {
        values++;
        *sum =*sum+ input;
        scanf("%d", &input);
    }
    return values;
}

int main() {
    double sum = 0;
    int values;
    values = read_values(&sum);
    printf("Average: %g\n",sum/values);
    return 0;
    }
