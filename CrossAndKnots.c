#include<stdio.h>
#include<stdlib.h>


int board[9]={ 0 };
int hand, cpuhand;

int main(void) {

	
	int winflag = 0; //ゲーム終わるフラグ 2:ユーザーの勝利　3:相手の勝利

	while (winflag < 1) {

		//----------------------------------------------------------------------------------------------------------------------------------
		printf("\n__________\n");
		int i;
		for (i = 0; i < 9; i++)
		{
			if (i % 3 == 0) {
				printf("\n");
			}
			if (board[i]) {
				if (board[i] == 10) {
					printf("[O]");
				}
				else if (board[i] == 11) {
					printf("[X]");
				}
			}
			else {
				//nullなら番号表示
				printf("(%d)", i);
			}

		}
		//----------------------------------------------------------------------------------------------------------------------------------
		//自分のターン
		int hand = 0;//初期化
		printf("\n\n\n");
		printf("手を入力してください\n");
		scanf("%d", &hand);
		
		board[hand] = 10;
		printf("自分：%d\n", hand);


		//勝利チェック
		//winflag = checkWin(hand, board);

		//縦チェック
		if (
			(board[hand - 3] == 10 && board[hand + 3] == 10)
			|| (board[hand - 3] == 10 && board[hand - 6] == 10)
			|| (board[hand + 3] == 10 && board[hand + 6] == 10)
			) {
			winflag = 2;
		}
		//横チェック	
		if (
			(board[hand - 1] == 10 && board[hand + 1] == 10)
			|| (board[hand - 1] == 10 && board[hand - 2] == 10)
			|| (board[hand + 1] == 10 && board[hand + 2] == 10)
			) {
			winflag = 2;
		}
		//右斜めチェック	
		if (
			(board[hand - 2] == 10 && board[hand + 2] == 10)
			|| (board[hand - 2] == 10 && board[hand - 4] == 10)
			|| (board[hand + 2] == 10 && board[hand + 4] == 10)
			) {
			winflag = 2;
		}
		//左斜めチェック	
		if (
			(board[hand - 4] == 10 && board[hand + 4] == 10)
			|| (board[hand - 4] == 10 && board[hand - 8] == 10)
			|| (board[hand + 4] == 10 && board[hand + 8] == 10)
			) {
			winflag = 2;
		}

		//----------------------------------------------------------------------------------------------------------------------------------
		//CPU
		do {
			cpuhand = 0;//初期化
			cpuhand = rand();
			cpuhand = cpuhand % 9;
		} while (board[cpuhand]>10);


		board[cpuhand] = 11;
		printf("CPU：%d\n", cpuhand);

		//縦チェック
		if (
			(board[cpuhand - 3] == 11 && board[cpuhand + 3] == 11)
			|| (board[cpuhand - 3] == 11 && board[cpuhand - 6] == 11)
			|| (board[cpuhand + 3] == 11 && board[cpuhand + 6] == 11)
			) {
			winflag = 3;
		}
		//横チェック	
		if (
			(board[cpuhand - 1] == 11 && board[cpuhand + 1] == 11)
			|| (board[cpuhand - 1] == 11 && board[cpuhand - 2] == 11)
			|| (board[cpuhand + 1] == 11 && board[cpuhand + 2] == 11)
			) {
			winflag = 3;
		}
		//右斜めチェック	
		if (
			(board[cpuhand - 2] == 11 && board[cpuhand + 2] == 11)
			|| (board[cpuhand - 2] == 11 && board[cpuhand - 4] == 11)
			|| (board[cpuhand + 2] == 11 && board[cpuhand + 4] == 11)
			) {
			winflag = 3;
		}
		//左斜めチェック	
		if (
			(board[cpuhand - 4] == 11 && board[cpuhand + 4] == 11)
			|| (board[cpuhand - 4] == 11 && board[cpuhand - 8] == 11)
			|| (board[cpuhand + 4] == 11 && board[cpuhand + 8] == 11)
			) {
			winflag = 3;
		}
		//----------------------------------------------------------------------------------------------------------------------------------



	}

	

	if (winflag==2) {
		printf("あなたの勝ち！！！\n");
	}
	else {
		printf("CPUの勝ち！！！\n");	
	}

	printf("ゲーム終了\n");

	return 0;

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

