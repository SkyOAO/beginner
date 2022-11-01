#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("************************\n");
	printf("*****1.play   0.exit****\n");
	printf("************************\n");
}
void game()
{
	char mine[ROWS][COLS];//存放布置好的雷的信息
	char show[ROWS][COLS];//存放排查出的雷的信息
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	SetMine(mine, ROW, COL);//布置雷
	//DisplayBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);//排查雷,在mine排查后把信息放入show中
}
int main()
{
	int input;
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
			printf("游戏退出\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}