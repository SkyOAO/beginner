#define ROW 3
#define COL 3
#include<stdio.h>//只要引用了game.h就相当于把头文件stdio引用了
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
//告诉我们四种游戏的状态
//玩家赢，返回字符*
//电脑赢，返回字符#
//平局，返回字符Q
//继续游戏，返回字符C
char IsWin(char board[ROW][COL], int row, int col);//因为返回的是字符，所以用char