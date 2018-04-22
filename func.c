#include <stdio.h>

/*

関数:複数の処理

返り値の型 関数名(引数, ...){
	処理:
	return 値;

}


int main(){}
も関数 C言語では一番最初に main関数をみる
main以下に何もなければ何も実行されない

int main(){}内のラストreturn 0は処理が無事に処理されたということ

*/



//プロトタイプ宣言：プログラムの最初にどのような関数が出てくるか宣言すること
float getMax(float a,float b);



//引数や返り値がない関数 voidをつける(何もないということ)
void sayHi(void){
	printf("hi!\n");
}


int main(void){

	float result;
	result = getMax(2.3,5.2);
	printf("%f\n",result);

	sayHi();
	return 0;
}

float getMax(float a,float b){
 
 		/*
    if(a >= b){
     return a;
    }else{
      return b;
    }
		*/
		//三項演算子 返り値 ＝ （条件）？A:B;
		return (a >= b) ? a : b;

}
