#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("*************************\n");
	printf("**** 1.play   0.exit ****\n");
	printf("*************************\n");
}
void game()//��Ϸ�������㷨ʵ��
{
	char board[ROW][COL] = { 'a'};//ȫ���ո�
	int ret;
	InitBoard(board, ROW, COL);//��ʼ�����̣�������ʼ�����������ϻ���ֶ�����ַ�a
	DisplayBoard(board, ROW, COL);//��ӡ����
	while (1)//����
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж������Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ�����Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	switch (ret)
	{
		case '*':
			printf("���Ӯ\n");
			break;
		case '#':
			printf("����Ӯ\n");
			break;
		default:
			printf("ƽ��\n");
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
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("ѡ�����������ѡ��\n");
				break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
