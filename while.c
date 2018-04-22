#include <stdio.h>

/*
ループ(while と do while)

whileと do while の違い

whileはdefault(それ以外)の値の時は一度も実行されない
while do は一回実行される
*/

int main(void){

  //while
  int m = 0;

  while (m < 10){
   printf("m: %d" , m);
    m++;
  }

  //do while

  int n=0;

  do{
    printf("n:%d\n", n);
    n++;
  }while(n<10);


  return 0;

}
