/*
��Ŀ����
�Ӽ�����������20����������ͳ�����еĸ���������������������ƽ��ֵ��

������λС��

�����ʽ
��
�����ʽ
��
��������
1 2 3 4 5 6 7 8 9 10
-1 -2 -3 -4 -5 -6 -7 -8 -9 -10
�������
10
5.50
*/

#include <stdio.h>

int main() 
{
    int arr[20],i;
    int countN = 0;
    int countP = 0;
    float sum = 0;
    for ( i = 0; i < 20; i++)
    {   
        scanf("%d",&arr[i]);
        if (arr[i] < 0)
        {
            countN++;
        }
        else
        {
            sum += arr[i];
            countP++;
        }
    }
    printf("%d\n%.2f",countN,sum/countP);
    return 0;
} 