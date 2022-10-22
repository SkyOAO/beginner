#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("*************************\n");
	printf("**** 1.play   0.exit ****\n");
	printf("*************************\n");
}
void game()//游戏的整个算法实现
{
	char board[ROW][COL] = { 'a'};//全部空格
	int ret;
	InitBoard(board, ROW, COL);//初始化棋盘，若不初始化，则棋盘上会出现定义的字符a
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (1)//下棋
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	switch (ret)
	{
		case '*':
			printf("玩家赢\n");
			break;
		case '#':
			printf("电脑赢\n");
			break;
		default:
			printf("平局\n");
			break;
	}
}
void test()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，请重新选择\n");
				break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
