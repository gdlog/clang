#include<stdio.h>
#include<stdlib.h>

int board[9]={ 0 };
int hand, cpuhand, turnuser;

//プロトタイプ宣言
int checkwinflag(int,int);
int printdata(int[]);


int main(void) {

	int winflag = 0; //ゲーム終わるフラグ
	int turnuser = 10; //

	while (winflag < 1) {

		//----------------------------------------------------------------------------------------------------------------------------------
		printdata(board);
		//----------------------------------------------------------------------------------------------------------------------------------
		if (turnuser==10) {
			//自分のターン
			int hand = 0;//初期化
			printf("\n\nあなたのターン\n手を入力してください\n自分：");
			scanf("%d", &hand);
			board[hand] = turnuser;
			winflag = checkwinflag(turnuser, hand);

			turnuser = 11;
		}
		else {

			do {
				cpuhand = 0;//初期化
				cpuhand = rand();
				cpuhand = cpuhand % 9;
			} while (board[cpuhand]>9);

			board[cpuhand] = turnuser;
			printf("\n\nCPUのターン\nCPU：%d\n", cpuhand);

			winflag = checkwinflag(turnuser, cpuhand);
			turnuser = 10;
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
		(board[0] == turn && board[3] == turn && board[6] == turn)
		|| (board[1] == turn && board[4] == turn && board[7] == turn)
		|| (board[2] == turn && board[5] == turn && board[8] == turn)
		) {
		//縦チェック
		checkwinflag = 1;
		printf("縦がそろった\n");
	}
	if (
		(board[0] == turn && board[1] == turn && board[2] == turn)
		|| (board[3] == turn && board[4] == turn && board[5] == turn)
		|| (board[6] == turn && board[7] == turn && board[8] == turn)
		) {
		//横チェック
		checkwinflag = 2;
		printf("横がそろった\n");
	}
	//真ん中だったら斜めチェックがはいる
	if (board[6] == turn && board[4] == turn && board[2] == turn) {
		//右斜めチェック	
		checkwinflag = 3;
		printf("右斜めがそろった\n");
	}
	if (board[0] == turn && board[4] == turn && board[8] == turn) {
		//左斜めチェック	
		checkwinflag = 4;
		printf("左斜めがそろった\n");
	}

	

	return checkwinflag;
}
