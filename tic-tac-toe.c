#include <stdlib.h>
#include <stdio.h>

// 打印棋盘函数
void chushiqipan(int arr[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("-%d-", arr[i][j]);
            if (j < 2)
            {
                printf("|");
            }
            else
                printf("\n");
        }
        if (i < 2)
        {
            printf("---|---|---\n");
        }
    }
}

// 玩家1落子函数
void wanjia1luozi(int arr[3][3])
{
    int i = 1;
    do
    {
        printf("\n请玩家1选择落子位置 ->");
        int m = 0;
        int r, c;
        scanf("%d%d", &r, &c);
        while ((getchar()) != '\n')
        {
            m = 1;
        }
        if (m == 1)
        {
            printf("\n输入i (空格)j形式，请重新输入\n");
            continue;
        }
        if (r < 0 || r > 3 || c < 0 || c > 3)
        {
            printf("\n非法位置，请重新选择\n");
            continue;
        }
        if (arr[r - 1][c - 1] == 0)
        {
            arr[r - 1][c - 1] = 1;
            i--;
        }
        else
        {
            printf("\n该位置已有棋子，请重新选择\n");
        }
    } while (i == 1);
    printf("\n\n***********************************\n");
}

// 玩家2落子函数
void wanjia2luozi(int arr[3][3])
{
    int i = 1;
    do
    {
        printf("\n请玩家2选择落子位置 ->");
        int m = 0;
        int r, c;
        scanf("%d%d", &r, &c);
        while ((getchar()) != '\n')
        {
            m = 1;
        }
        if (m == 1)
        {
            printf("\n输入i (空格)j形式，请重新输入\n");
            continue;
        }
        if (r < 0 || r > 3 || c < 0 || c > 3)
        {
            printf("\n非法位置，请重新选择\n");
            continue;
        }
        if (arr[r - 1][c - 1] == 0)
        {
            arr[r - 1][c - 1] = 2;
            i--;
        }
        else
        {
            printf("\n该位置已有棋子，请重新选择\n");
        }
    } while (i == 1);
    printf("\n\n***********************************\n");
}

// 判断玩家1输赢
int panduan1shuying(int arr[3][3])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] == 1)
        {
            printf("\n玩家1赢了\n");
            return 1;
        }
        else if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] == 1)
        {
            printf("\n玩家1赢了\n");
            return 1;
        }
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == 1)
    {
        printf("\n玩家1赢了\n");
        return 1;
    }
    else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] == 1)
    {
        printf("\n玩家1赢了\n");
        return 1;
    }
    return 0;
}

// 判断玩家2输赢
int panduan2shuying(int arr[3][3])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] == 2)
        {
            printf("\n玩家2赢了\n");
            return 2;
        }
        else if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] == 2)
        {
            printf("\n玩家2赢了\n");
            return 2;
        }
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == 2)
    {
        printf("\n玩家2赢了\n");
        return 2;
    }
    else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] == 2)
    {
        printf("\n玩家2赢了\n");
        return 2;
    }
    return 0;
}
// 判断平局
int pingju(int arr[3][3])
{
    int pin = 1;
    int i;
    int j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
            {
                pin = 0;
            }
        }
    }
    if (pin == 1)
    {
        printf("\n平局\n\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    // 菜单界面
    printf("*******井字棋***********************\n");
    printf("玩法介绍：\n");
    printf("玩家1、2轮流在棋盘上下子，先连3子成一条线的玩家获胜。\n\n");
    printf("输入i (空格)j 表示 下在第i行第j列,如1 2表示下在第1行第2列\n\n");
    printf("***输入1开始游戏\n");
    printf("***输入0退出游戏\n");
    printf("***********************************\n");
    int n;
    while (1)
    {
        printf("\n请输入 -> ");
        int m = 0;
        scanf("%d", &n);
        while ((getchar()) != '\n')
        {
            m = 1;
        }
        if (m == 1)
        {
            printf("\n输入0或1，请重新输入\n");
            continue;
        }
        if (n == 1 || n == 0)
        {
            printf("\n********进入游戏********\n");
            break;
        }
        else
        {
            printf("\n输入0或1，请重新输入\n");
        }
    }

    int qipan[3][3] = {0};

    // 游戏主体
    while (n == 1)
    {
        // 打印棋盘
        printf("\n");
        chushiqipan(qipan);

        // 判断输赢
        if (panduan2shuying(qipan) == 2)
        {
            break;
        }
        if (pingju(qipan) == 1)
        {
            break;
        }

        // 玩家1落子
        wanjia1luozi(qipan);

        // 打印棋盘
        printf("\n");
        chushiqipan(qipan);

        // 判断输赢
        if (panduan1shuying(qipan) == 1)
        {
            break;
        }
        if (pingju(qipan) == 1)
        {
            break;
        }

        // 玩家2落子
        wanjia2luozi(qipan);
    }
    // 结束游戏
    printf("感谢游玩!\n");
    system("pause");
    return 0;
}