#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  char *outputName = malloc((strlen(inputName) + 7) * sizeof(char*));
  strcpy(outputName, inputName);
  strcat(outputName, ".counts");
  return outputName;
}
