/*
题目描述
写两个函数，分别求两个整数的最大公约数和最小公倍数，用主函数调用这两个函数，并输出结果两个整数由键盘输入。
输入格式
两个数
输出格式
最大公约数 最小公倍数
样例输入
6 15
样例输出
3 30
*/

#include <stdio.h>

// 最大公约数
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

// 最小公倍数
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