#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("-------------ɨ����Ϸ---------------\n");
	for (i = 0; i <= row; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------ɨ����Ϸ---------------\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;//����10����
	while (count)
	{
		int x = rand() % row + 1;//������������whileѭ���ڣ�����ÿѭ��һ�����ɲ�ͬ���������������
		int y = rand() % col + 1;
		if (mine[x][y] == '0')//��Ŀ���������ʱ���ܷ��ף������ظ�����
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';//�õ�ASCII��ֵ�ļ���
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;//�ж��Ƿ�ʤ��������
	while (win < row * col - EASY_COUNT)//��win�Լӵ�����û���׵ĸ�����ʱ������ѭ��ȥ�ж�
	{
		printf("������Ҫ�Ų������:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź�����ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//�����׵�����£���ʾ������Χ�м�����
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//���ַ�0�������ָ�����ַ����֣�����ASCII��ֵ��
				//��ʾ�Ų������Ϣ
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
			printf("����Ƿ�������������\n");
	}
	if (win == row * col - EASY_COUNT)
		printf("��ϲ�㣬���׳ɹ�\n");
}