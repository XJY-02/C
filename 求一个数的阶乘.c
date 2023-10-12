// 使用循环和递归2种方法完成该题。

#include <stdio.h>

//循环函数
int loop(int n)
{   
    int i;
    int s = 1;
    for ( i = 0; i < n; i++)
    {  
        s *= (i+1);
    }
    return s;
}

//递归函数
int recursion(int m)
{   
    if (m <= 1)
    {
        return 1;
    }
    else
        return m * recursion(m-1);
    
}

int main()
{   
    int i;
    scanf("%d",&i);
    printf("循环得出结果 = %d",loop(i));
    printf("递归得出结果 = %d",recursion(i));
    return 0;
}
