/*
题目描述
求矩阵的两对角线上的元素之和

输入格式
矩阵的行数N
和一个N*N的整数矩阵a[N][N](N<=10)

输出格式
所输矩阵的两对角线上的元素之和

样例输入
3
1 2 3
4 5 6
7 8 9
样例输出
25
*/

#include <stdio.h>

int main()
{
    int dim;
    scanf("%d", &dim);
    int arr[dim][dim];
    int i, j;
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int sum = 0;

    for (i = 0; i < dim; i++)
    {
        sum += (arr[i][i] + arr[dim - 1 - i][i]);
    }
    if (dim % 2 == 1)
    {
        sum -= arr[(dim - 1) / 2][(dim - 1) / 2];
    }

    printf("%d ", sum);

    return 0;
}
