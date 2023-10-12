/*
题目描述
一球从M米高度自由下落，每次落地后返回原高度的一半，再落下。 它在第N次落地时反弹多高？共经过多少米？ 保留两位小数
输入格式
M N
输出格式
它在第N次落地时反弹多高？共经过多少米？ 保留两位小数，空格隔开，放在一行
样例输入
1000 5
样例输出
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