// ʹ��ѭ���͵ݹ�2�ַ�����ɸ��⡣

#include <stdio.h>

//ѭ������
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

//�ݹ麯��
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
    printf("ѭ���ó���� = %d",loop(i));
    printf("�ݹ�ó���� = %d",recursion(i));
    return 0;
}
