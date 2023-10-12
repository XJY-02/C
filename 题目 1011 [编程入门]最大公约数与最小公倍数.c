/*
题目描述
输入两个正整数m和n，求其最大公约数和最小公倍数。
输入格式
两个整数
输出格式
最大公约数，最小公倍数
样例输入
5 7
样例输出
1 35
*/

#include <stdio.h>
//求小和求大
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
//求最大公约数
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

//求最小公倍数
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