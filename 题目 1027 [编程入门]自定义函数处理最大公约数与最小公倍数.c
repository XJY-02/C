/*
��Ŀ����
д�����������ֱ����������������Լ������С�������������������������������������������������ɼ������롣
�����ʽ
������
�����ʽ
���Լ�� ��С������
��������
6 15
�������
3 30
*/

#include <stdio.h>

// ���Լ��
int gcd(int n, int m)
{
    if (n % m == 0)
    {
        return m;
    }
    else if (m % n == 0)
    {
        return n;
    }
    return (n > m ? (gcd(n - m, n)) : (gcd(n, m - n)));
}

// ��С������
int lcm(int n, int m)
{
    return (n * m / gcd(n, m));
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d ", gcd(a, b));
    printf("%d", lcm(a, b));
    return 0;
}