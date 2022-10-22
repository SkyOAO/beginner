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
			board[i][j] = ' ';//将棋盘数据初始化为空格
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//数据的打印和分割行的打印看成一组
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)//与col列有关，修改col的值时会保证棋盘的正常形状，打印时将|和数组数据一起打印
		{
			printf(" %c ", board[i][j]);//打印一行的数据(arr[i][0]  arr[i][1]  arr[i][2])
			if (j < col - 1)//最后一组(arr[i][2])不打印竖杠
				printf("|");
		}
		printf("\n");//用来使棋盘成形
		if (i < row - 1)//最下方不打印分割行
		{
			for (j = 0; j < col; j++)
			{
				printf("---");//打印分割行
				if (j < col - 1)//最后一列没有竖杠
					printf("|");//先---再|就很好地避免了竖杠打印在最左侧
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("玩家走:");
	while (1)//没有条件限制的循环（无限循环），一般最后通过if条件配合break跳出循环
	{
		printf("请输入要下的坐标:");
		scanf("%d%d", &x, &y);
		//判断x,y坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)//用户不一定是程序员，不知道数组的第一个下标是0，所以是从x>=1开始
		{
			if (board[x - 1][y - 1] == ' ')//x和y是从1开始的所以需要-1
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该坐标被占用\n");
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("电脑走:\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')//电脑默认0为下标，不需要像用户那样，所以是x,y
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
				return 0;//没满
		}
	}
	return 1;//满了
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//横三行判断三子
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (i = 0; i < col; i++)//竖三列
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	//两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	if (1 == IsFull(board, ROW, COL))//判断是否平局
		return 'Q';
	return 'C';
}