// ʹ��ѭ���͵ݹ�2�ַ�����ɸ��⡣

#include <stdio.h>

//ѭ������
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

//�ݹ麯��
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
    printf("ѭ���ó���� = %d",loop(i));
    printf("�ݹ�ó���� = %d",recursion(i));
    return 0;
}
