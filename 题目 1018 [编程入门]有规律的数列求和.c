/*
��Ŀ����
��һ�������У� 2/1 3/2 5/3 8/5 13/8 21/13...... ���������е�ǰN��֮�ͣ�������λС����
�����ʽ
N
�����ʽ
����ǰN���
��������
10
�������
16.48
*/

#include <stdio.h>

int main() 
{
    int n;
    scanf("%d",&n);
    float arr1[n];
    float arr2[n];
    float arr3[n];
    float sum = 0;
    int i;
    arr1[0] = 2;
    arr1[1] = 3;
    arr2[0] = 1;
    arr2[1] = 2;
    for ( i = 2; i < n; i++)
    {
        arr1[i] = arr1[i-1] + arr1[i-2]; 
        arr2[i] = arr2[i-1] + arr2[i-2];
    }
    for ( i = 0; i < n; i++)
    {
        arr3[i] = arr1[i] / arr2[i];
        sum += arr3[i];
    }
    printf("%.2f",sum);
    return 0;
} 