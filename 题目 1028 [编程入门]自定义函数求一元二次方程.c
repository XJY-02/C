/*
题目描述
求方程 a*x^2 + b*x + c = 0 的根，用三个函数分别求当b^2-4ac大于0、等于0、和小于0时的根，并输出结果。从主函数输入a、b、c的值。
输入格式
a b c
输出格式
x1=? x2=?
样例输入
4 1 1
样例输出
x1=-0.125+0.484i x2=-0.125-0.484i
*/

#include <stdio.h>
#include <math.h>

// b^2-4ac大于0时
void dayu0(float a, float b, float c)
{
    float panbieshi = pow(b, 2) - 4 * a * c;
    float x1 = (-b + sqrt(panbieshi)) / (2 * a);
    float x2 = (-b - sqrt(panbieshi)) / (2 * a);
    printf("x1=%.3f x2=%.3f", x1, x2);
}

// b^2-4ac等于0时
void dengyu0(float a, float b, float c)
{
    float panbieshi = pow(b, 2) - 4 * a * c;
    float x1 = (-b + sqrt(panbieshi)) / (2 * a);
    float x2 = (-b - sqrt(panbieshi)) / (2 * a);
    printf("x1=%.3f x2=%.3f", x1, x2);
}

// b^2-4ac小于0时
void xiaoyu0(float a, float b, float c)
{

    float panbieshi = pow(b, 2) - 4 * a * c;
    float x1shibu = (-b) / (2 * a), x2shibu = (-b) / (2 * a);
    float x1xubu = (sqrt(-panbieshi)) / (2 * a), x2xubu = (sqrt(-panbieshi)) / (2 * a);
    printf("x1=%.3f+%.3fi x2=%.3f-%.3fi", x1shibu, x1xubu, x2shibu, x2xubu);
}

int main()
{
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    float panbieshi = pow(b, 2) - 4 * a * c;
    if (panbieshi > 0)
    {
        dayu0(a, b, c);
    }
    else if (panbieshi == 0)
    {
        dengyu0(a, b, c);
    }
    else if (panbieshi < 0)
    {
        xiaoyu0(a, b, c);
    }
    return 0;
}