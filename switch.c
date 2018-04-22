#include <stdio.h>
/*
条件分岐
*/

int main(void){

  int rank = 2;

  switch(rank){
    case 1 :
      printf("Gold");
      break;
    case 2 :
      printf("Silver");
      break;
    case 3 :
      printf("Bronze");
      break;
    default :
      printf("no medal ...");
      break;

  }


  return 0;
}                                                       
