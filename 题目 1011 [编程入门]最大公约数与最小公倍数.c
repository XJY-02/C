/*
��Ŀ����
��������������m��n���������Լ������С��������
�����ʽ
��������
�����ʽ
���Լ������С������
��������
5 7
�������
1 35
*/

#include <stdio.h>
//��С�����
int max(int n, int m)
{
    if(n<m)
        return m;
    else
        return n;
}

int min(int n, int m)
{
    if(n>m)
        return m;
    else
        return n;
}
//�����Լ��
int gcd(int n,int m)
{
    int gcd = 1;
    int i;
    for ( i = 1; i < min(n,m); i++)
    {
        if (n % i == 0 && m % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;

}

//����С������
int lcm(int n, int m)
{
    int lcm = m * n;
    int i;
    for ( i = m * n; i >= max(n,m); i--)
    {
        if (i % n == 0 && i % m == 0)
        {
            lcm = i;
        }
        
    }
    return lcm;

}

int main() 
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d %d",gcd(a,b),lcm(a,b));
    return 0;
} 