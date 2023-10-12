/*
题目描述
有一分数序列： 2/1 3/2 5/3 8/5 13/8 21/13...... 求出这个数列的前N项之和，保留两位小数。
输入格式
N
输出格式
数列前N项和
样例输入
10
样例输出
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