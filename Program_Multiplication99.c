printf("九九表\n");
	printf("__________\n\n");
	int i,j,answer;
	for (i = 1; i <= 9; i++)
	{
	for (j = 1; j <= 9; j++)
	{
		answer = 0;//初期化
		answer = i*j;
		printf("%d×%d=%02d | ", i,j,answer);
	}
	printf("\n", i, j, answer);
	}
	printf("__________\n\n");
