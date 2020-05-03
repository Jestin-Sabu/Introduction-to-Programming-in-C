#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int *array, size_t n)
{
  int a = 1, b = 1;
  if(n<=0)
    return 0;
  if(array == NULL)
    return 0;
  
  for(int i=1;i<n;i++){
    if(array[i-1]<array[i])
      a++;
    else
      a=1;
    if(a>b)
      b = a;
  }
  return b;
}
  
