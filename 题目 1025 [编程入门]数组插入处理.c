/*
��Ŀ����
����һ���������źõ�9��Ԫ�ص����飬������һ����Ҫ��ԭ������Ĺ��ɽ������������С�
�����ʽ
��һ�У�ԭʼ���С� �ڶ��У���Ҫ��������֡�
�����ʽ
����������
��������
1 7 8 17 23 24 59 62 101
50
�������
1
7
8
17
23
24
50
59
62
101
*/

#include <stdio.h>

int main()
{
    int arr[9] = {0};
    int i;
    for (i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
    }
    int input;
    scanf("%d", &input);
    int count = 9;
    for (i = 0; i < 9; i++)
    {
        if (arr[i] > input)
        {
            count = i;
            break;
        }
    }
    for (i = 0; i < 9; i++)
    {
        if (i == count)
        {
            printf("%d\n", input);
        }
        printf("%d\n", arr[i]);
    }

    return 0;
}
