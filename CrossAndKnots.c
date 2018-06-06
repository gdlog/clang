#include<stdio.h>
#include<stdlib.h>


int board[9]={ 0 };
int hand, cpuhand, turnuser, turnvalue;

//プロトタイプ宣言
int checkwinflag(int,int);
int printdata(int[]);


int main(void) {

	int winflag = 0; //ゲーム終わるフラグ
	int turnuser = 1; //

	while (winflag < 1) {

		//----------------------------------------------------------------------------------------------------------------------------------
		printdata(board);
		//----------------------------------------------------------------------------------------------------------------------------------
		if (turnuser==1) {
			//自分のターン
			turnvalue = 10;
			int hand = 0;//初期化
			printf("\n\nあなたのターン\n手を入力してください\n自分：");
			scanf("%d", &hand);
			board[hand] = 10;
			winflag = checkwinflag(turnvalue, hand);

			turnuser = 2;
		}
		else {
			turnvalue = 11;
			do {
				cpuhand = 0;//初期化
				cpuhand = rand();
				cpuhand = cpuhand % 9;
			} while (board[cpuhand]>9);

			board[cpuhand] = turnvalue;
			printf("\n\nCPUのターン\nCPU：%d\n", cpuhand);

			winflag = checkwinflag(turnvalue, cpuhand);
			turnuser = 1;
		}


	}

	printf("ゲーム終了\n");
	printdata(board);

	//----------------------------------------------------------------------------------------------------------------------------------
	



	return 0;

}

int printdata(int data[]) {

	int i;
	for (i = 0; i < 9; i++)
	{
		if (i % 3 == 0) {
			printf("\n");
		}
		if (data[i]) {
			if (data[i] == 10) {
				printf("[O]");
			}
			else if (data[i] == 11) {
				printf("[X]");
			}
		}
		else {
			//nullなら番号表示
			printf("(%d)", i);
		}

	}
	printf("\n__________\n");
}

//winflagまとめ
int checkwinflag(int turn, int turnshand)
{
	int checkwinflag=0;
	if (
		(board[turnshand - 3] == turn && board[turnshand + 3] == turn)
		|| (board[turnshand - 3] == turn && board[turnshand - 6] == turn)
		|| (board[turnshand + 3] == turn && board[turnshand + 6] == turn)
		) {
		//縦チェック
		checkwinflag = 1;
		printf("縦がそろった\n");
	}
	if (
		(board[turnshand - 1] == turn && board[turnshand + 1] == turn)
		|| (board[turnshand - 1] == turn && board[turnshand - 2] == turn)
		|| (board[turnshand + 1] == turn && board[turnshand + 2] == turn)
		) {
		//横チェック
		checkwinflag = 2;
		printf("横がそろった\n");
	}
	if (
		(board[turnshand - 2] == turn && board[turnshand + 2] == turn)
		|| (board[turnshand - 2] == turn && board[turnshand - 4] == turn)
		|| (board[turnshand + 2] == turn && board[turnshand + 4] == turn)
		) {
		//右斜めチェック	
		checkwinflag = 3;
		printf("右斜めがそろった\n");
	}
	if (
		(board[turnshand - 4] == turn && board[turnshand + 4] == turn)
		|| (board[turnshand - 4] == turn && board[turnshand - 8] == turn)
		|| (board[turnshand + 4] == turn && board[turnshand + 8] == turn)
		) {
		//左斜めチェック	
		checkwinflag = 4;
		printf("左斜めがそろった\n");
	}

	return checkwinflag;
}



/*


int checkWin(int hand,int board[]){

	int flag, tate, tate2;
	flag = 0;
	tate = hand-3;
	tate2 = hand + 3;

	//縦チェック
	if (board[tate] == 10&& board[tate2] == 10) {
		flag = 3;
	}

	return flag;

}


int getCpuhand() {
cpuhand = 0;
cpuhand = rand();
cpuhand = cpuhand % 9;
//null判定
return cpuhand;
}




//すべてに０を代入
int data[3][3] = { 0 };
int i, j, answer;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
answer = 0;//初期化
answer = i * j;
printf("%d×%d=%02d | ", i, j, answer);
}
printf("\n");
}



*/

