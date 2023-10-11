/*
sum=2+5+8+11+14+…，输入正整数n，求sum的前n项和。
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    int i;
    int sum = 0;
    for ( i = 0; i < n ; i++)
    {
        arr[i] = 3*i + 2;
        sum += arr[i];
    }
    printf("%d",sum);
    
    return 0;
} 