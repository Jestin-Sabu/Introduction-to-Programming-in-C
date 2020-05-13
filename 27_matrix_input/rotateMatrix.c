#include<stdio.h>
#include<stdlib.h>

void readMatrix(char matrix[10][10], char *filename){
  int c, i=0, j=0;
  FILE *f = fopen(filename,"r");
  if(f == NULL){
    fprintf(stderr,"Failed to open the file");
    exit (EXIT_FAILURE);
  }
  while((c = fgetc(f)) != EOF){
    if(c == '\n'){
      if(j != 10){
	fprintf(stderr,"Invalid no. of elements in a row");
	exit(EXIT_FAILURE);
      }
      i++;
      j=0;
      continue;
    }
    if(i >= 10){
      fprintf(stderr,"Excess row");
      exit (EXIT_FAILURE);
    }
    matrix[i][j] = c;
    j++;
  }
  if(i<10){
    fprintf(stderr,"Few rows");
    exit (EXIT_FAILURE);
  }
  if(fclose(f) != 0){
    fprintf(stderr,"Failed to close the file");
    exit(EXIT_FAILURE);
  }
}

void rotate(char matrix[10][10]) {
  int size = 10;
  int ptrLeft, ptrRight;
  char tmp;
  for (int i = 0; i < size; i++) {
    ptrLeft = 0;
    ptrRight = size - 1;
    while (ptrLeft < ptrRight) {
      tmp = matrix[i][ptrLeft];
      matrix[i][ptrLeft] = matrix[i][ptrRight];
      matrix[i][ptrRight] = tmp;
      ptrLeft++;
      ptrRight--;
    }
  }
  int new_x, new_y;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      new_x = size - 1 - j;
      new_y = size - 1 - i;
      tmp = matrix[i][j];
      matrix[i][j] = matrix[new_x][new_y];
      matrix[new_x][new_y] = tmp;
    }
  }
}

void print(char matrix[10][10]){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++)
      printf("%c",matrix[i][j]);
    printf("\n");
  }
}

int main(int argc, char **argv){
  if(argc != 2){
    fprintf(stderr,"Invalid no. of arguments");
    exit (EXIT_FAILURE);
  }
  char matrix[10][10];
  char *filename = argv[1];
  readMatrix(matrix, filename);
  rotate(matrix);
  print(matrix);
  return EXIT_SUCCESS;
}
