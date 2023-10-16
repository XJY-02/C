/*
题目描述
已有一个已正序排好的9个元素的数组，今输入一个数要求按原来排序的规律将它插入数组中。
输入格式
第一行，原始数列。 第二行，需要插入的数字。
输出格式
排序后的数列
样例输入
1 7 8 17 23 24 59 62 101
50
样例输出
1
7
8
17
23
24
50
59
62
101
*/

#include <stdio.h>

int main()
{
    int arr[9] = {0};
    int i;
    for (i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
    }
    int input;
    scanf("%d", &input);
    int count = 9;
    for (i = 0; i < 9; i++)
    {
        if (arr[i] > input)
        {
            count = i;
            break;
        }
    }
    for (i = 0; i < 9; i++)
    {
        if (i == count)
        {
            printf("%d\n", input);
        }
        printf("%d\n", arr[i]);
    }

    return 0;
}
