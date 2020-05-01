#include<stdio.h>
#include<stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void printdetails (int currentAge, double currentBalance){
  printf("Age %3d month %2d you have $%.2lf\n", currentAge/12, currentAge%12, currentBalance);
}

double balancecalculator(retire_info state, double currentBalance){
  double currentInterest = state.rate_of_return/12;
  return (currentBalance*currentInterest) + state.contribution;
}

void retirement (int startAge, double intial, retire_info working, retire_info retired){
  int currentAge = startAge;
  double currentBalance = intial;
  double net = 0;
  while (currentAge < working.months + startAge) {
      printdetails(currentAge, currentBalance);
      net = balancecalculator(working, currentBalance);
      currentBalance += net;
      currentAge++;
  }
  printf("Done\n");
  while (currentAge < startAge +  working.months + retired.months){
      printdetails(currentAge, currentBalance);
      net = balancecalculator(retired, currentBalance);
      currentBalance += net;
      currentAge++;
   }
 }

int main(void){
  retire_info working, retired;
  
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01;

  int Age = 327;
  double Savings = 21345;

  retirement( Age, Savings, working, retired);
  return EXIT_SUCCESS;
}
  
  
    
    
