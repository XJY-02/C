/*
�ж�һ�����Ƿ�Ϊ"ˮ�ɻ���"����ν"ˮ�ɻ���"��ָ������һ������������һ����λ����
��Σ����λ���ֵ������͵��ڸ����������磺371��һ��"ˮ�ɻ���"��371=3^3+7^3+1^3.
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
