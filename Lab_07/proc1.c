#include <stdio.h>

int sum(int m, int n){
  return m + n;
}

int main(){
  int m = 10;
  int n = 5;

  int x = sum(m,n);
  printf("%d\n", x);
    
    return 0;
}
