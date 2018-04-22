#include <stdio.h>

/*
変数の有効範囲

変数の有効期限
なし 一回ずつ破棄
static 保持

*/

int a = 7; //グローバル変数

void f(void){
	
	//int a = 0; //ローカル変数&自動変数
	static int a = 0; //static 静的変数プログラム全体で保持
	a++;
	printf("%d\n",a);

}

int main(void){

	f();
	f();
	f();
	printf("main %d\n",a);
	return 0;

}
