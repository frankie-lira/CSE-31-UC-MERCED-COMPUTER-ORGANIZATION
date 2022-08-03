//
//  main.c
//  Punishment
//
//  Created by Francisco Lira on 9/9/20.
//  Copyright © 2020 Francisco Lira. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int f;
    int n;
    int typo;
    
    char a[100] = "C programming language is the best!\n";
    char b[100] = "C programmming lnguage is the bet!\n";
    
    printf("Enter the number of repetitions for the punishment phrase: ");
       scanf("%d",&f);
       
       if(f < 0)
           printf("\nYou entered an invalid value for the number of repetitions!\n");
       else
       {
           printf("Enter the repetition count when you wish to introduce a typo: ");
           scanf("%d",&typo);
           
           if(typo < 1 || typo > f)
               printf("You entered an invalid value for the typo placement!\n");
           else
           {
               for(n = 1; n <= f; n++)
               {
                   if(n != typo)
                       printf("%s",a);
                   else
                       printf("%s",b);
               }
           }
       }
    return 0;
}
