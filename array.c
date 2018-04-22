#include <stdio.h>


/*

配列[]：intの配列[]
int i[] = {1,2,3}

文字列：charの配列[](終端は\0)
				(	x stringではない )
char s[]= {"a","b","c","\0"};
上記を省略して
char s[]= "abc";
もしくは
char s[4]= "abc"; //\0を含む要素数
と書くことも可能


*/


int main(void){

	int sales[3]; //３列領域を確保
	sales[0]=200;
	sales[1]=300;
	sales[2]=400;

	int sales2[] = {200,400,300};

	char s[]= "abc";

	printf("%c\n", s[1]);



	return 0;
}
