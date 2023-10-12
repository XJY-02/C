/*
题目描述
求以下三数的和,保留2位小数 1~a之和 1~b的平方和 1~c的倒数和
输入格式
a b c
输出格式
1+2+...+a + 1^2+2^2+...+b^2 + 1/1+1/2+...+1/c
样例输入
100 50 10
样例输出
47977.93
*/

#include <stdio.h>

int main() {
    float a,b,c;
    scanf("%f%f%f",&a,&b,&c);
    float sum_a = 0;
    float sum_b = 0;
    float sum_c = 0;
    float i;

    for ( i = 1; i < a+1; i++)
    {
        sum_a += i;
    }
    // printf("%.2f\n",sum_a);

    for ( i = 1; i < b+1; i++)
    {
        sum_b += i*i;
    }
    // printf("%.2f\n",sum_b);

    for ( i = 1; i < c+1; i++)
    {
        sum_c += (1/i);
    }
    // printf("%.2f\n",sum_c);
    
    float sum = sum_a + sum_b +sum_c;
    printf("%.2f",sum);
    return 0;
} 