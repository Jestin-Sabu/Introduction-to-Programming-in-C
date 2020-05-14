#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

char ** read(FILE *stream, int *size){
  char *line = NULL;
  char **output = NULL;
  size_t sz = 0;
  while((getline(&line,&sz,stream)) >= 0){
    output = realloc(output,(*size+1)*sizeof(char*));
    output[*size] = line;
    (*size)++;
    line = NULL;
  }
  free(line);
  return output;
}

void print(char **output, int size){
  for(int i=0;i<size;i++)
    printf("%s",output[i]);
}

int main(int argc, char ** argv){
  char ** output = NULL;
  int size = 0,max = 0;
  if(argc == 1){
    output = read(stdin,&size);
    sortData(output,size);
    print(output,size);
    for(int i=0;i<size;i++)
      free(output[i]);
    free(output);
  }
  else{
    for(int i=1;i<argc;i++){
      FILE *f = fopen(argv[i],"r");
      if(f == NULL){
	fprintf(stderr,"Failed to open the file %s.",argv[i]);
	exit(EXIT_FAILURE);
      }
      output = read(f,&size);
      if((fclose(f) != 0)){
	fprintf(stderr,"Failed to close the file %s.",argv[i]);
	exit(EXIT_FAILURE);
      }
      sortData(output,size);
      print(output,size);
      output = NULL;
      if(size>max)
	max = size;
    }
    for(int j=0;j<max;j++)
      free(output[j]);
    free(output);
  }
  return EXIT_SUCCESS;
}
