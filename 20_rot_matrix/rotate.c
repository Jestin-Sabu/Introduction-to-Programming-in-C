#include<stdio.h>

void rotate(char matrix[10][10]){
  int a,b,c,d;
  char temp;  
  for(a=0,b=9;a<4;a++,b--){
    for(c=a,d=b;c<b;c++,d--){
      temp = matrix[a][c];
      matrix[a][c] = matrix[d][a];
      matrix[d][a] = matrix[b][d];
      matrix[b][d] = matrix[c][b];
      matrix[c][b] = temp;
    }
  }
  
}
