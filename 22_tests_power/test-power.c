#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned power(unsigned x, unsigned y);

int main(void){
  if(power(0,0) !=1){
    printf("Failed.\n");
    return EXIT_FAILURE;
  }
  if(power(2,0) !=1){
    printf("Failed.\n");
    return EXIT_FAILURE;
  }
  if(power(-2,0) !=1){
    printf("Failed.\n");
    return EXIT_FAILURE;
  }
  if(power(2,2) !=4){
    printf("Failed.\n");
    return EXIT_FAILURE;
  }
  if(power(0,5) !=0){
    printf("Failed.\n");
    return EXIT_FAILURE;
  }
  if(power(-2,2) !=4){
    printf("Failed.\n");
    return EXIT_FAILURE;
  }
  if(power(1,10) !=1){
    printf("Failed.\n");
    return EXIT_FAILURE;
  }
  if(power(3,2) !=9){
    printf("Failed.\n");
    return EXIT_FAILURE;
  }
  if(power(0,0) !=1){
    printf("Failed.\n");
    return EXIT_FAILURE;
  }
  if(power(-2,1) !=(-2)){
    printf("Failed.\n");
    return EXIT_FAILURE;
  }
  printf("Success\n");
  return EXIT_SUCCESS;
}
