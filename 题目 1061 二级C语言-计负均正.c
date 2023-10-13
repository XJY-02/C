/*
题目描述
从键盘输入任意20个整型数，统计其中的负数个数并求所有正数的平均值。

保留两位小数

输入格式
无
输出格式
无
样例输入
1 2 3 4 5 6 7 8 9 10
-1 -2 -3 -4 -5 -6 -7 -8 -9 -10
样例输出
10
5.50
*/

#include <stdio.h>

int main() 
{
    int arr[20],i;
    int countN = 0;
    int countP = 0;
    float sum = 0;
    for ( i = 0; i < 20; i++)
    {   
        scanf("%d",&arr[i]);
        if (arr[i] < 0)
        {
            countN++;
        }
        else
        {
            sum += arr[i];
            countP++;
        }
    }
    printf("%d\n%.2f",countN,sum/countP);
    return 0;
} 