/*
��Ŀ����
һ���M�׸߶��������䣬ÿ����غ󷵻�ԭ�߶ȵ�һ�룬�����¡� ���ڵ�N�����ʱ������ߣ������������ף� ������λС��
�����ʽ
M N
�����ʽ
���ڵ�N�����ʱ������ߣ������������ף� ������λС�����ո����������һ��
��������
1000 5
�������
31.25 2875.00
*/

#include <stdio.h>
#include <math.h>

int main() {
    float M;
    int N;
    scanf("%f%d",&M,&N);
    float H;
    float S;
    int i;
    H = M / pow(2,N);
    printf("%.2f ",H);
    if (N == 1)
    {
        S = M;
    }
    else
    {
        for ( i = 0; i < N-1; i++)
        {
            S += M / pow(2,i);
        }
        S += M;
    }
    printf("%.2f",S);
    return 0;
} 