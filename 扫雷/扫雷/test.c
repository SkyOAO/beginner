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
	char mine[ROWS][COLS];//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS];//����Ų�����׵���Ϣ
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	SetMine(mine, ROW, COL);//������
	//DisplayBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);//�Ų���,��mine�Ų�����Ϣ����show��
}
int main()
{
	int input;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}