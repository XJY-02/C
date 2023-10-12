// 使用循环和递归2种方法完成该题。

#include <stdio.h>

//循环函数
int loop(int n)
{   
    int i;
    int arr[n];
    arr[0] = 1;
    arr[1] = 1;
    for ( i = 2; i < n; i++)
    {  
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n-1];
}

//递归函数
int recursion(int m)
{   
    if (m <= 2)
    {
        return 1;
    }
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
