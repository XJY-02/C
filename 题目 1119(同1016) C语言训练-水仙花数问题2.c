/*
�ж�һ�����Ƿ�Ϊ"ˮ�ɻ���"����ν"ˮ�ɻ���"��ָ������һ������������һ����λ����
��Σ����λ���ֵ������͵��ڸ����������磺371��һ��"ˮ�ɻ���"��371=3^3+7^3+1^3.
������е�"ˮ�ɻ���"(��С�����˳�����,һ��һ��)
*/

/* 
    ����1��
#include <stdio.h>
#include <math.h>

int main() {
    int m;
    int n;
    int i;
    for ( m = 100; m < 1000; m++)
    {   
        n = m;
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
            printf("%d\n",m);
        }
    }
    return 0;
} 
*/



//  ����2��
#include <stdio.h>
#include <math.h>

int main() {
    int a;
    int b;
    int c;
    for ( a = 1; a < 10; a++)
    {
        for ( b = 0; b < 10; b++)
        {
            for ( c = 0; c < 10; c++)
            {
                int num = 100 * a + 10 * b + c;
                int sum = pow(a,3)+pow(b,3)+pow(c,3);
                if (num == sum)
                    printf("%d\n",sum);
            }
            
        }
        
    }
    return 0;
}



