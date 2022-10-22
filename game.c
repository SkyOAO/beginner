#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//���������ݳ�ʼ��Ϊ�ո�
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//���ݵĴ�ӡ�ͷָ��еĴ�ӡ����һ��
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)//��col���йأ��޸�col��ֵʱ�ᱣ֤���̵�������״����ӡʱ��|����������һ���ӡ
		{
			printf(" %c ", board[i][j]);//��ӡһ�е�����(arr[i][0]  arr[i][1]  arr[i][2])
			if (j < col - 1)//���һ��(arr[i][2])����ӡ����
				printf("|");
		}
		printf("\n");//����ʹ���̳���
		if (i < row - 1)//���·�����ӡ�ָ���
		{
			for (j = 0; j < col; j++)
			{
				printf("---");//��ӡ�ָ���
				if (j < col - 1)//���һ��û������
					printf("|");//��---��|�ͺܺõر��������ܴ�ӡ�������
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("�����:");
	while (1)//û���������Ƶ�ѭ��������ѭ������һ�����ͨ��if�������break����ѭ��
	{
		printf("������Ҫ�µ�����:");
		scanf("%d%d", &x, &y);
		//�ж�x,y����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�û���һ���ǳ���Ա����֪������ĵ�һ���±���0�������Ǵ�x>=1��ʼ
		{
			if (board[x - 1][y - 1] == ' ')//x��y�Ǵ�1��ʼ��������Ҫ-1
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�����걻ռ��\n");
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("������:\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')//����Ĭ��0Ϊ�±꣬����Ҫ���û�������������x,y
		{
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;//û��
		}
	}
	return 1;//����
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//�������ж�����
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (i = 0; i < col; i++)//������
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	//�����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	if (1 == IsFull(board, ROW, COL))//�ж��Ƿ�ƽ��
		return 'Q';
	return 'C';
}