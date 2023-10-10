/*
判断一个数是否为"水仙花数"，所谓"水仙花数"是指这样的一个数：首先是一个三位数，
其次，其各位数字的立方和等于该数本身。例如：371是一个"水仙花数"，371=3^3+7^3+1^3.
*/

#include <stdio.h>
#include <math.h>

int main() {
    int m;
    int n;
    int i;
    scanf("%d",&m);
    n = m;
    if ( m >= 100 && m < 1000)
    {
        int arr[3];
        for ( i = 0; i < 3; i++)
        {
            arr[i] = n % 10;
            n /= 10;
        }
        int sum = 0;
        for ( i = 0; i < 3; i++)
        {
            sum += pow(arr[i],3);
        }
        if (m == sum)
        {
            printf("%d",1);
        }
        else
            printf("%d",0);   
    }
    else 
        printf("%d", 0);
    return 0;
}
