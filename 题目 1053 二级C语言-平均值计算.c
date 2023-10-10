/*
输入10个整数，求它们的平均值，并输出大于平均值的数据的个数。
*/

#include <stdio.h>

int main() {
    int arr[10];
    int i;
    int sum = 0;
    int count = 0;
    for ( i = 0; i < 10; i++)
    {
        scanf("%d",&arr[i]);
    }
    for ( i = 0; i < 10; i++)
    {
        sum += arr[i];
    }
    int average = sum / 10;
        for ( i = 0; i < 10; i++)
    {  
        if ( arr[i] > average )
        {
            count++;
        }
        
    }
    printf("%d", count);
    return 0;
}
