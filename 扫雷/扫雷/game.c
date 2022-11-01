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
	printf("-------------扫雷游戏---------------\n");
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
	printf("-------------扫雷游戏---------------\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;//布置10个雷
	while (count)
	{
		int x = rand() % row + 1;//随机数必须放在while循环内，才能每循环一次生成不同的随机数来放置雷
		int y = rand() % col + 1;
		if (mine[x][y] == '0')//当目标格子无雷时才能放雷，避免重复放雷
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
		mine[x + 1][y + 1] - 8 * '0';//用到ASCII码值的计算
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;//判断是否胜利的条件
	while (win < row * col - EASY_COUNT)//当win自加到等于没有雷的格子数时，跳出循环去判定
	{
		printf("请输入要排查的坐标:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//不是雷的情况下，显示坐标周围有几个雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//加字符0让它变成指定的字符数字（根据ASCII码值）
				//显示排查出的信息
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
			printf("坐标非法，请重新输入\n");
	}
	if (win == row * col - EASY_COUNT)
		printf("恭喜你，排雷成功\n");
}