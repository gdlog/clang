#include <stdio.h>

//globalで使う
#define BOARD_W  8 //盤の大きさ
#define BOARD_H   8 //盤の高さ


int board[BOARD_H][BOARD_W] = { 0 };
int flag, turn;

//プロトタイプ宣言
int View();
int Input();

int main(void)
{
	flag = 0; //終了フラグ初期化
	turn = 1; //ターンは自分から 自分1 相手2

	while (1) 
	{
		View();
		if (flag == 1) 
		{
			return 0; //ループを抜ける
		}
		else 
		{
			Input();

		}
		return 0;
	}
}

int View() 
{
	printf("\n__________________________________________________\n\n");
	int i, j;
	for (i = 0; i < BOARD_H; i++) 
	{
		for (j = 0; j < BOARD_W; j++) 
		{
			switch (board[i][j])
			{
				case 0:
					printf(" %d-%d ",i,j);
					break;
				case 1:
					printf("  ●  ");
					break;
				case 2:
					printf("  〇  ");
					break;
			}
			printf("|");
		}
		printf("\n__________________________________________________\n\n");
	}
}

int Input()
{
	int x, y;
	printf("\n\nあなたのターン\n手を入力してください\n自分：");
	scanf("%d", &x);
	scanf("%d", &y);
	
	if (board[y][x] == 0)
	{
		board[y][x] = turn;
		turn = turn % 2 + 1;
	}


}
