/*
��Ŀ����
��һ��3��3����Խ���Ԫ��֮�͡�
�����ʽ
����
�����ʽ
���Խ��� ���Խ��� Ԫ�غ�
��������
1 2 3
1 1 1
3 2 1
�������
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
