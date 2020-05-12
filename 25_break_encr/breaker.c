#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int keyfinder(FILE* f){
  int alpha[26] = {0},max,j,c;
  while((c=fgetc(f)) != EOF){
    if(isalpha(c)){
      c -= 'a';
      alpha[c]++;
    }
  }
  max = alpha[0];
  for(int i=0;i<26;i++){
    if(alpha[i]>max){
      max = alpha[i];
      j=i;
    }
    if(j>=('e'-'a'))
       return j-('e'-'a');
    else
      return (26-('e'-'a'))+j;
}
int main(int argc, char** argv){
  if(argc != 2){
    fprintf(stderr,"Usage: inputFilename\n");
    return EXIT_FAILURE;
  }
  FILE* f = fopen(argv[1],"r");
  if(f == NULL){
    perror("Could not open the file\n");
    return EXIT_FAILURE;
  }
  int key = keyfinder(f);
  printf("%d\n",key);
  fclose(f);
  return EXIT_SUCCESS;
}
  
