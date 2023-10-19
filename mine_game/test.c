#include "game.h"

void menu1()
{
    printf("******************************\n");
    printf("*******      扫雷     ********\n");
    printf("******   1. 开始游戏   *******\n");
    printf("******   2. 退出游戏    ******\n");
    printf("******************************\n");
}

void again()
{
    printf("********************************\n");
    printf("*******   是否再来一局？   *****\n");
    printf("*******   1. 再来一把！   ******\n");
    printf("*******   2. 退出游戏     ******\n");
    printf("********************************\n");
}

void game()
{
    // 雷的信息储存
    //  1. 布置好的雷的信息
    char mine[ROWS][COLS] = {0}; // 11 * 11
    //  2. 排查出的雷的信息
    char show[ROWS][COLS] = {0};
    // 初始化
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    // 打印棋盘
    DisplayBoard(show, ROW, COL);
    // 布置雷
    SetMine(mine, ROW, COL);
    // DisplayBoard(mine, ROW, COL);//取消注释可以看初始布雷图。

    // 选择插旗还是扫雷
    int input = 0;
    int new = 1;
    do
    {
        if (new) // 首次说明
        {
            printf("\n  说明：\n");
            printf("1.输入1 2表示第一行第二列\n");
            printf("2.输入0 0重新选择排查还是插旗\n");
            printf("3.被插旗坐标可以被排查\n\n");
            new = 0;
        }
        printf("请选择1.排查 2.插旗:>");
        scanf("%d", &input);
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

        int boom = 0;
        switch (input)
        {
        case 1:
            boom = FindMine(mine, show, ROW, COL); // 扫雷
            break;
        case 2:
            Flag_Planting(show, ROW, COL); // 插旗
            break;
        default:
            printf("选择错误，请重新选择\n");
            break;
        }

        // 判断输赢

        // 输——踩到炸弹
        if (boom)
        {
            break;
        }
        // 赢
        int i = 0;
        int j = 0;
        int opened_num = 0;
        for (i = 1; i <= ROW; i++)
        {
            for (j = 1; j <= COL; j++)
            {
                if (show[i][j] != '*' && show[i][j] != 'X')
                {
                    opened_num++;
                }
            }
        }
        if (opened_num == ROW * COL - EASY_COUNT)
        {
            DisplayBoard(mine, ROW, COL);
            printf("恭喜你，排雷成功！<(￣︶￣)>\n");
            break;
        }
    } while (1);
}

void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    int new = 1;
    do
    {
        if (new)
        {
            menu1();
            new = 0;
        }
        else
        {
            again();
        }
        printf("请选择:>");
        scanf("%d", &input);

        int mistakeinput = 0;
        while ((getchar()) != '\n')
        {
            mistakeinput = 1;
        }
        if (mistakeinput)
        {
            printf("选择错误，请重新选择\n");
            new = 1;
            continue;
        }

        switch (input)
        {
        case 1:
            game();
            break;
        case 2:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误，请重新选择\n");
            new = 1;
            break;
        }

    } while (input != 2);
}

int main()
{
    test();
    system("pause");
    return 0;
}