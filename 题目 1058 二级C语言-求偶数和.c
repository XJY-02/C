/*
���Ƴ�������n��������n�Ӽ������룬n>0����������ǵ�ż���͡�
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