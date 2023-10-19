#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int rows, int cols)
{
    int i = 0;
    int j = 0;
    // 打印列号
    printf("    ");
    for (i = 1; i <= cols; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    printf("  ");
    for (i = 0; i <= cols; i++)
    {
        if (i < 10)
        {
            printf("--");
        }
        else
        {
            printf("---");
        }
    }
    printf("\n");
    for (i = 1; i <= rows; i++)
    {
        printf("%d", i); // 打印行号
        if (i < 10)
        {
            printf(" ");
        }
        printf("|");
        for (j = 1; j <= cols; j++)
        {
            if (j >= 10)
            {
                printf(" ");
            }

            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

void SetMine(char board[ROWS][COLS], int rows, int cols)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % rows + 1; // 1~9
        int y = rand() % cols + 1; // 1~9
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

char Get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    int count = 0;
    int i = 0;
    int j = 0;
    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            if (mine[i][j] == '1')
            {
                count++;
            }
        }
    }

    return count + '0';
}

int Check_if_there_are_any_unchecked_areas_around(char show[ROWS][COLS], int x, int y)
{
    int i = 0;
    int j = 0;
    int result = 0;
    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            if (show[i][j] == '*')
            {
                result = 1;
            }
        }
    }
    return result;
}

void Check_adjacent_coordinates(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
    int i = 0;
    int j = 0;
    // 点开周围8个坐标
    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            if (show[i][j] == '*' && (i != x || j != y))
            {
                show[i][j] = Get_mine_count(mine, i, j);
            }
        }
    }
    for (i = x - 1; i <= x + 1; i++) // 在相邻3行
    {
        for (j = y - 1; j <= y + 1; j++) // 在相邻三列
        {
            if (i != x || j != y) // 中心周围的坐标（由于也是周围有没被点开的格子的坐标，可以不加该条限制，但是加了可以减少运行时间）
            {
                if (show[i][j] == '0') // 其中周围没有地雷的坐标
                {
                    if (i >= 1 && i <= COL && j >= 1 && j <= COL) // 在棋盘内的坐标
                    {
                        if (Check_if_there_are_any_unchecked_areas_around(show, i, j)) // 周围有没被点开的格子的坐标
                        {
                            Check_adjacent_coordinates(mine, show, i, j);
                        }
                    }
                }
            }
        }
    }
}

int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
    int x = 0;
    int y = 0;
    int mistake = 0;
    int sure = 0;
    do
    {
        int mistake = 0;
        printf("请输入排查的坐标:>");
        scanf("%d%d", &x, &y);
        // 坐标非法时
        while ((getchar()) != '\n')
        {
            mistake = 1;
        }
        if (x == 0 && y == 0 && mistake == 0) // 返回选择
        {
            break;
        }
        if (x < 1 || x > rows || y < 1 || y > cols)
        {

            mistake = 1;
        }
        if (mistake)
        {
            printf("坐标非法，请重新输入\n"); // 非法范围
            continue;
        }
        // 坐标合法时

        if (show[x][y] != '*' && show[x][y] != 'X')
        {
            printf("已经排查过该坐标\n");
            continue;
        }

        if (show[x][y] == 'X') // 是旗帜位置
        {
            do
            {
                printf("是否确定排查该旗帜位置？\n1.是 2.否:>");
                scanf("%d", &sure);
                int mistakeinput = 0;
                while ((getchar()) != '\n')
                {
                    mistakeinput = 1;
                }
                if (mistakeinput)
                {
                    printf("选择错误，请重新选择\n");
                    continue;
                }
                if (sure == 1 || sure == 2)
                {
                    break;
                }
                else
                {
                    printf("选择错误，请重新选择\n");
                }
            } while (1);
        }
        if (sure == 2)
        {
            continue;
        }

        if (mine[x][y] == '1') // 踩到雷
        {
            DisplayBoard(mine, ROW, COL);
            printf("你被炸死了╥﹏╥ \n再来一次吧！\n");
            return 1;
        }

        // 没有踩到雷，也不是旗帜位置
        show[x][y] = Get_mine_count(mine, x, y);
        if (show[x][y] == '0') // 如果该坐标周围8格没有雷
        {
            Check_adjacent_coordinates(mine, show, x, y); // 展开排查周围8格
        }
        DisplayBoard(show, ROW, COL);
        break;
    } while (1);
    return 0;
}

void Flag_Planting(char show[ROWS][COLS], int rows, int cols)
{
    int x = 0;
    int y = 0;
    int mistake = 0;
    do
    {
        int mistake = 0;
        printf("请输入插旗的坐标:>");
        scanf("%d%d", &x, &y);
        // 坐标非法时
        while ((getchar()) != '\n')
        {
            mistake = 1;
        }
        if (x == 0 && y == 0 && mistake == 0) // 返回选择
        {
            break;
        }
        if (x < 1 || x > rows || y < 1 || y > cols)
        {

            mistake = 1;
        }
        if (mistake)
        {
            printf("坐标非法，请重新输入\n"); // 非法范围
            continue;
        }
        // 坐标合法时
        if (show[x][y] != '*') // 该坐标已排查
        {
            if (show[x][y] == 'X')
            {
                printf("该坐标已有旗帜\n");
            }
            else
            {
                printf("已经排查过该坐标\n");
            }
            continue;
        }
        else
        {
            show[x][y] = 'X';
            DisplayBoard(show, ROW, COL);
            break;
        }
    } while (1);
}