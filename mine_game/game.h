// 库函数引用
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 设置难度————几行几列，多少炸弹
#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY_COUNT 10

// 函数声明
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int rows, int cols);
void SetMine(char board[ROWS][COLS], int rows, int cols);
int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols);
char Get_mine_count(char mine[ROWS][COLS], int x, int y);
void Check_adjacent_coordinates(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
int Check_if_there_are_any_unchecked_areas_around(char show[ROWS][COLS], int x, int y);
void Flag_Planting(char show[ROWS][COLS], int rows, int cols);