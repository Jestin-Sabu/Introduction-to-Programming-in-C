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
  if(argc == 1){
    int size = 0;
    char **output = read(stdin,&size);
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
      int size = 0;
      char **output = read(f,&size);
      if((fclose(f) != 0)){
	fprintf(stderr,"Failed to close the file %s.",argv[i]);
	for (int j=0;j<size;j++)
	  free(output[j]);
	free(output);
	exit(EXIT_FAILURE);
      }
      sortData(output,size);
      print(output,size);
      for(int j=0;j<size;j++)
	free(output[j]);
      free(output);
    }
  }
  return EXIT_SUCCESS;
}
