#include<stdio.h>

int main(void) {


	int month,day;
	printf("月と日にちを入力してください\n");
	scanf("%d%d", &month,&day);
	printf("月は%d\n", month);
	printf("日付は%d\n", day);
	
	// 重みづけ
	int amount;
	amount = month * 100;
	amount += day;

	if (amount >= 204 && amount <= 505) {
		//2/4~5/5
			printf("春です");
	}
	else if (amount >= 506 && amount <= 808)
	{
		printf("夏です");
	}
	else if (amount >= 809 && amount <= 1107)
	{
		printf("秋です");
	}
	else if (amount >= 1108 || amount <= 203)
	{
		printf("冬です");
	}
	else {
		printf("値おかしくない？");
	}
	return 0;

}
