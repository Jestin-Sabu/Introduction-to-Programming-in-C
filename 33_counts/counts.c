#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  counts_t *temp = malloc(sizeof(*temp));
  temp->count = NULL;
  temp->numcount = 0;
  temp->unknown = 0;
  return temp;
}
void addCount(counts_t * c, const char * name) {
  if(name == NULL)
    c->unknown++;
  else{
    int  flag =0;
    int limit = c->numcount;
    for(int i=0;i<limit;i++){
      if((strcmp((c->count[i]->name), name)) == 0){
	c->count[i]->count++;
	flag = 1;
      }
    }
    if(flag == 0){
      one_count_t *temp = malloc(sizeof(*temp));
      temp->name = malloc(sizeof(name));
      strcpy(temp->name, name);
      temp->count = 1;;
      c->count = realloc((c->count), (c->numcount+1)*sizeof(*c->count));
      c->count[c->numcount++] = temp;
    }
  }
}
void printCounts(counts_t * c, FILE * outFile) {
  int limit = c->numcount;
  for(int i=0;i<limit;i++)
    fprintf(outFile,"%s: %d\n",c->count[i]->name,c->count[i]->count);
  if(c->unknown != 0)
    fprintf(outFile,"<unknown>: %d\n",c->unknown);
}

void freeCounts(counts_t * c) {
  int limit = c->numcount;
  for(int i=0;i<limit;i++){
    free(c->count[i]->name);
    free(c->count[i]);
  }
  free(c->count);
  free(c);
}
