#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int *array, size_t n)
{
  int a = 0, b = 0;
  if(n<=0)
    return 0;
  if(array == NULL)
    return 0;
  
  for(int i=0;i<n;i++){
    if(array[i]<array[i+1])
      a++;
    else
      a=0;
    if(a>b)
      b = a;
  }
  return b;
}
  
