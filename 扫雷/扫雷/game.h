#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10//简单模式10个雷
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);//数组没变，传过来的还是11*11的数组，所以是ROWS,COLS，而只打印9*9的框的内容，所以是row,col
void SetMine(char mine[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);