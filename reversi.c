#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE  6 //盤の一辺のマス数

int board[BOARD_SIZE][BOARD_SIZE] = { 0 }; //盤の初期化
int turn; //プレイヤーのターン

//プロトタイプ宣言
void View();
void Input();
void Judge(int a , int b);
int PreJudge(int a, int b);
void Result();

int main(void)
{
	turn = 1; //ターンは自分から 自分1 相手2
	board[BOARD_SIZE / 2][BOARD_SIZE / 2] = 1;
	board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 - 1] = 1;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1] = 2;
	board[BOARD_SIZE / 2-1][BOARD_SIZE / 2] = 2;


	while (1)
	{
		View();
		Result();
		Input();
		system("cls"); // 画面の初期化
	}

	return 0;
}

void View()
{
	printf("\n[リバーシ] Player1:●  Player2:〇 \n");

	printf("\n");


	int i, j;
	for (i = 0; i < BOARD_SIZE; i++)
	{


		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j]==0) 
			{
				int prejudge = PreJudge(i, j);
				if (prejudge == 1) 
				{
					printf("★");
				}
				else 
				{
					printf("%d%d", j, i);
				}
							
			}
			else if (board[i][j] == 1) 
			{
				printf("●");
			}
			else if (board[i][j] == 2)
			{
				printf("〇");

			}


			printf("|");
		}
		printf("\n");

	}

}

void Input()
{
	int x, y;
	printf("\n\nPlayer%dのターン\n手を入力してください\n",turn);
	scanf_s("%d %d", &x,&y);
	//scanf_s("%d", &y);

	if (board[y][x] == 0)
	{
		board[y][x] = turn;
		turn = turn % 2 + 1;
	}

	Judge(y,x);

	
}


void Judge(int h, int w) {

	//int vec_h[] = { -1, 1}; int vec_w[] = { 0, 0}; //上下 //int vec_h[] = { 0, 0 }; int vec_w[] = { -1, 1 }; //左右	//int vec_h[] = { -1, 1 }; int vec_w[] = { 1, -1 }; //右斜め//int vec_h[] = { -1, 1 }; int vec_w[] = { -1, 1 }; //左斜め
	int vec_h[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; int vec_w[] = { -1, 0, 1, -1, 1, -1, 0, 1 };	//上下左右ななめを判別

	int dir_h,dir_w;

	for (int i = 0; i < sizeof(vec_h) / sizeof(vec_h[0]); ++i) {
		for (int j = 0; j < sizeof(vec_w) / sizeof(vec_w[0]); ++j) {

			dir_h = vec_h[i];
			dir_w = vec_w[j];

			if (board[h+ dir_h][w+dir_w] == turn )
			{ 
				for (int d = 1; d <= BOARD_SIZE; d++)
				{
					
					if (board[h + (dir_h * d)][w + (dir_w * d)] == turn % 2 + 1)
					{
						for (int dm = d; dm >= 0; dm--)
						{
							board[h + (dir_h*dm)][w + (dir_w*dm)] = turn % 2 + 1;
						}
						break;
					}
				}

			}

		}
	}
}


//--------------------------------
// 描画と事前判定
//--------------------------------
int PreJudge(int h, int w) {

	int vec_h[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; int vec_w[] = { -1, 0, 1, -1, 1, -1, 0, 1 };	//上下左右ななめを判別
	int dir_h, dir_w;
	int sc = 0;


	for (int i = 0; i < sizeof(vec_h) / sizeof(vec_h[0]); ++i) {
		for (int j = 0; j < sizeof(vec_w) / sizeof(vec_w[0]); ++j) {

			dir_h = vec_h[i];
			dir_w = vec_w[j];

			if (board[h + dir_h][w + dir_w] == turn % 2 + 1)
			{

				for (int d = 1; d <= BOARD_SIZE; d++)
				{
					
					if (board[h + (dir_h * d)][w + (dir_w * d)] == turn)
					{
						if (sc==0) {
							sc = 1;
							return 1;
						}
						break;
					}
				}

			}

		}
	}
}



void Result()
{
	int i, j;
	int count[3] = {0};

	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			switch (board[i][j])
			{
			case 0:
				count[0] += 1;
				break;
			case 1:
				count[1] += 1;
				break;
			case 2:
				count[2] += 1;
				break;
			}
		}

	}
	printf("debug:\n");
	printf("Player1:%d枚\nPlayer2:%d枚\n残り:%d枚\n", count[1], count[2],count[0]);


	//マス目残り０によるゲーム終了
	if (count[0] == 0) {
		printf("ゲーム終了！\n");
		printf("Player1:%d個 : Player2:%d個", count[1], count[2]);

		if (count[1] > count[2]) {
			printf("Player1の勝利!");
		}
		else {
			printf("Player2の勝利!");
		}

	}
	//持ち駒0によるゲーム終了
	if (count[1] == 0 or count[2] == 0) {
		printf("ゲーム終了！");

		if (count[1] > count[2]) {
			printf("Player1の勝利!");
		}
		else {
			printf("Player2の勝利!");
		}

	}

}
