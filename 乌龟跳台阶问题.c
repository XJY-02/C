/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

/* 
解题思路
首先知道从0级台阶跳到1级台阶只有1种跳法，跳到2级台阶有2种跳法。
考虑跳到第3级台阶，只能有2种来源：
1、是从1级台阶+2得来。
2、是从2级台阶+1得来。
这两种跳法互相独立不重复。
故跳第3级的方式 = 跳第1级的方式 + 跳第2级的方式。
......
第i级 同理 = （i-1）的方式+（i-2）的方式。
*/

#include <stdio.h>

//循环函数
int loop(int n)
{   
    int i;
    int arr[n];
    arr[0] = 1;
    arr[1] = 2;
    for ( i = 2; i < n; i++)
    {  
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n-1];
}

//递归函数
int recursion(int m)
{   
    if (m == 0)
        return 0;
    else if (m == 1)
        return 1;
    else if (m == 2)
        return 2;
    else
        return recursion(m-1) + recursion(m-2);
    
}

int main()
{   
    int i;
    scanf("%d",&i);
    printf("循环得出结果 = %d",loop(i));
    printf("递归得出结果 = %d",recursion(i));
    return 0;
}
