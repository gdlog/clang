#include <stdio.h>

/*

ポインタ：アドレスを格納するための変数　
メモリ(記憶領域)

& : アドレス演算子 アドレスを持ってくる
* : 間接演算子　アドレス部分に入ってる"値"を間接的に持ってくる(ポインタ変数宣言時の*とは異なる)
*/

//メモリの節約　値渡し(値を保持)と参照渡し(直接書き換え)
void swap( int *pa, int *pb){
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb =tmp;

}

//ポインターを使うことで直接あたいを書き換えポインター分だけのメモリ消費に抑える
//void f(long a){
void f(long *pa){ //アドレスを渡す
      *pa = *pa + 100;
      printf("%ld",*pa); //long d
}

int main(void){
	

	int a =5;
	int b = 10;
	swap(&a , &b);
	printf("a:%d , b:%d \n" , a,b);



	/*
	int a;
	a = 10;

	//ポインター変数

	int *pa;
	pa = &a; //アドレスを代入

	printf("%d\n",*pa); 
	*/

	//メモリの節約
	//long a = 1000; //longは大きい数字型
	//f(a)
	//f(&a); //アドレスを渡す
	
	
	return 0;
				
}
