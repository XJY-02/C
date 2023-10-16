/*
题目描述
求一个3×3矩阵对角线元素之和。
输入格式
矩阵
输出格式
主对角线 副对角线 元素和
样例输入
1 2 3
1 1 1
3 2 1
样例输出
3 7
*/

#include <stdio.h>

int main()
{
    int arr[3][3] = {0};
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int sum_zhu = 0;
    int sum_fu = 0;

    for (i = 0; i < 3; i++)
    {
        sum_zhu += arr[i][i];
    }
    printf("%d ", sum_zhu);

    for (i = 0; i < 3; i++)
    {
        sum_fu += arr[2 - i][i];
    }
    printf("%d", sum_fu);
    return 0;
}
