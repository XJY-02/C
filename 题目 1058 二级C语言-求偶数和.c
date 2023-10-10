/*
编制程序，输入n个整数（n从键盘输入，n>0），输出它们的偶数和。
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    int i;

    for ( i = 0; i < n; i++)
    {   
        scanf("%d",&arr[i]);
    }
    int even_sum = 0;
    for ( i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even_sum += arr[i];
        }
    }
    printf("%d",even_sum);
    
    return 0;
} 