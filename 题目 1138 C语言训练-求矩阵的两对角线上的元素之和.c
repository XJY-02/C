/*
��Ŀ����
���������Խ����ϵ�Ԫ��֮��

�����ʽ
���������N
��һ��N*N����������a[N][N](N<=10)

�����ʽ
�����������Խ����ϵ�Ԫ��֮��

��������
3
1 2 3
4 5 6
7 8 9
�������
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
