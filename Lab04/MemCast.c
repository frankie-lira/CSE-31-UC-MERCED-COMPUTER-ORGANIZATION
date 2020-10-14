//
//  main.c
//  MemCast
//
//  Created by Francisco Lira on 9/24/20.
//
#include <stdio.h>

int main(){
    int i;
    int four_ints[4];
    char* four_c;

    for(i = 0; i < 4; i++)
        four_ints[i] = 2;

    printf("%x\n", four_ints[0]);
    
    four_c = (char*)four_ints;

    for(i = 0; i < 4; i++)
        four_c[i] = 'A'; // ASCII value of 'A' is 65 or 0x41 in Hex.
    
    // Add your code for the exercises here:
    printf("Value of four_ints[0]: %x\n", four_ints[0]);
    printf("Value of four_ints[1]: %x\n", four_ints[1]);
    printf("Address of four_ints: %p Address of four_c: %p \n", four_ints, four_c);
    
    for(i = 0; i < 4; i++){
        printf("element no. %d address: %p\n", i, four_ints + i);
        printf("element no. %d value: %x\n", i, four_ints + i);
    }
    printf("\n");
    
    for(i = 0; i < 4; i++){
        printf("element no. %d address: %p\n", i, four_c + i);
        printf("element no. %d value: %x\n", i, four_c + i );
    }
    return 0;
}
