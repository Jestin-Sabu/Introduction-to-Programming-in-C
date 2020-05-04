#include<stdio.h>
#include<stdlib.h>

unsigned power(unsigned x, unsigned y){
  int ans;
  if(x>=0){
    if(y==1)
      return x;
    else if (y==0)
      return 1;
    else
      return x*power(x,y-1);
  }
  else
    {
      x *= (-1);
      ans = power(x,y);
      if(x%2 == 0)
	return ans;
      else
	return ans*(-1);
    }
}
