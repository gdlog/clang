	
	int hand, cpuhand,i;
	i = 0; //買った回数
	while(i < 3){
		printf("\n\n");
		printf("勝った回数：%d\n",i);

		cpuhand = 0;
		cpuhand = rand();
		cpuhand = cpuhand % 3;
		printf("CPU：%d\n", cpuhand);

		hand = 0;
		printf("ジャンケン 1:ぐー	 2:ちょき　 3:ぱー　\n");
		scanf("%d", &hand);
		printf("自分：%d\n", hand);


		if (hand == cpuhand) {
			printf("あいこ\n");
		}else{
			if (hand == 1) { //自分がグー
				if (cpuhand == 2) {
					printf("勝ち\n");
					i++;
				}else {
					printf("負け\n");
				}
			}else if(hand == 2) { //自分がチョキ
				if (cpuhand == 3) {
					printf("勝ち\n");
					i++;
				}else {
					printf("負け\n");
				}
			}
			else if (hand == 3) { //自分がパー
				if (cpuhand == 1) {
					printf("勝ち\n");
					i++;
				}else {printf("負け\n");}
			}
		}

	}
	printf("3回勝った\n");

