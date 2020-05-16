#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"


kvpair_t* split(char *line){
  char * value = strchr(line,'=');
  *value = '\0';
  value++;
  char* key = strchr(line, '\n');
  if(key!= NULL)
    *key = '\0';
  key = line;
  kvpair_t *temp = malloc(sizeof(*temp));
  temp->value = value;
  temp->key = key;
  return temp;
}

kvarray_t * readKVs(const char * fname) {
  FILE *f = fopen(fname,"r");
  if(f == NULL){
    fprintf(stderr,"Failed to Open the file.\n");
    return NULL;
  }
  kvarray_t *kvarray = malloc(sizeof(*kvarray));
  kvpair_t *temp;
  int numarray = 0;
  char *line = NULL;
  size_t size = 0;
  while((getline(&line,&size,f)) >=0){
    temp = split(line);
    kvarray->pair = realloc((kvarray->pair), (numarray+1)*sizeof(kvarray->pair));
    kvarray->pair[numarray++] = temp;
    line = NULL;
    temp = NULL;
  }
  free(line);
  kvarray->numarray = numarray;
  if(fclose(f)!=0){
    fprintf(stderr,"Failed to close the file.\n");
    return NULL;
  }
  return kvarray;
}

void freeKVs(kvarray_t * pairs) {
  int limit = pairs->numarray;
  for(int i=0;i<limit;i++){
    free(pairs->pair[i]->key);
    free(pairs->pair[i]);
  }
  free(pairs->pair);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  kvpair_t *temp = NULL;
  int limit = pairs->numarray;
  for(int i=0;i<limit;i++){
    temp = pairs->pair[i];
    printf("key = %s value = %s\n",temp->key, temp->value);
    temp = NULL;
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  kvpair_t *temp = NULL;
  int limit = pairs->numarray;
  for(int i=0;i<limit;i++){
    temp = pairs->pair[i];
    if((strcmp(temp->key,key)) == 0)
      return temp->value;
    temp = NULL;
  }
  return NULL;
}
