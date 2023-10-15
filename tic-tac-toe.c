#include <stdlib.h>
#include <stdio.h>

// ��ӡ���̺���
void chushiqipan(int arr[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("-%d-", arr[i][j]);
            if (j < 2)
            {
                printf("|");
            }
            else
                printf("\n");
        }
        if (i < 2)
        {
            printf("---|---|---\n");
        }
    }
}

// ���1���Ӻ���
void wanjia1luozi(int arr[3][3])
{
    int i = 1;
    do
    {
        printf("\n�����1ѡ������λ�� ->");
        int m = 0;
        int r, c;
        scanf("%d%d", &r, &c);
        while ((getchar()) != '\n')
        {
            m = 1;
        }
        if (m == 1)
        {
            printf("\n����i (�ո�)j��ʽ������������\n");
            continue;
        }
        if (r < 0 || r > 3 || c < 0 || c > 3)
        {
            printf("\n�Ƿ�λ�ã�������ѡ��\n");
            continue;
        }
        if (arr[r - 1][c - 1] == 0)
        {
            arr[r - 1][c - 1] = 1;
            i--;
        }
        else
        {
            printf("\n��λ���������ӣ�������ѡ��\n");
        }
    } while (i == 1);
    printf("\n\n***********************************\n");
}

// ���2���Ӻ���
void wanjia2luozi(int arr[3][3])
{
    int i = 1;
    do
    {
        printf("\n�����2ѡ������λ�� ->");
        int m = 0;
        int r, c;
        scanf("%d%d", &r, &c);
        while ((getchar()) != '\n')
        {
            m = 1;
        }
        if (m == 1)
        {
            printf("\n����i (�ո�)j��ʽ������������\n");
            continue;
        }
        if (r < 0 || r > 3 || c < 0 || c > 3)
        {
            printf("\n�Ƿ�λ�ã�������ѡ��\n");
            continue;
        }
        if (arr[r - 1][c - 1] == 0)
        {
            arr[r - 1][c - 1] = 2;
            i--;
        }
        else
        {
            printf("\n��λ���������ӣ�������ѡ��\n");
        }
    } while (i == 1);
    printf("\n\n***********************************\n");
}

// �ж����1��Ӯ
int panduan1shuying(int arr[3][3])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] == 1)
        {
            printf("\n���1Ӯ��\n");
            return 1;
        }
        else if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] == 1)
        {
            printf("\n���1Ӯ��\n");
            return 1;
        }
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == 1)
    {
        printf("\n���1Ӯ��\n");
        return 1;
    }
    else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] == 1)
    {
        printf("\n���1Ӯ��\n");
        return 1;
    }
    return 0;
}

// �ж����2��Ӯ
int panduan2shuying(int arr[3][3])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] == 2)
        {
            printf("\n���2Ӯ��\n");
            return 2;
        }
        else if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] == 2)
        {
            printf("\n���2Ӯ��\n");
            return 2;
        }
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == 2)
    {
        printf("\n���2Ӯ��\n");
        return 2;
    }
    else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] == 2)
    {
        printf("\n���2Ӯ��\n");
        return 2;
    }
    return 0;
}
// �ж�ƽ��
int pingju(int arr[3][3])
{
    int pin = 1;
    int i;
    int j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
            {
                pin = 0;
            }
        }
    }
    if (pin == 1)
    {
        printf("\nƽ��\n\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    // �˵�����
    printf("*******������***********************\n");
    printf("�淨���ܣ�\n");
    printf("���1��2���������������ӣ�����3�ӳ�һ���ߵ���һ�ʤ��\n\n");
    printf("����i (�ո�)j ��ʾ ���ڵ�i�е�j��,��1 2��ʾ���ڵ�1�е�2��\n\n");
    printf("***����1��ʼ��Ϸ\n");
    printf("***����0�˳���Ϸ\n");
    printf("***********************************\n");
    int n;
    while (1)
    {
        printf("\n������ -> ");
        int m = 0;
        scanf("%d", &n);
        while ((getchar()) != '\n')
        {
            m = 1;
        }
        if (m == 1)
        {
            printf("\n����0��1������������\n");
            continue;
        }
        if (n == 1 || n == 0)
        {
            printf("\n********������Ϸ********\n");
            break;
        }
        else
        {
            printf("\n����0��1������������\n");
        }
    }

    int qipan[3][3] = {0};

    // ��Ϸ����
    while (n == 1)
    {
        // ��ӡ����
        printf("\n");
        chushiqipan(qipan);

        // �ж���Ӯ
        if (panduan2shuying(qipan) == 2)
        {
            break;
        }
        if (pingju(qipan) == 1)
        {
            break;
        }

        // ���1����
        wanjia1luozi(qipan);

        // ��ӡ����
        printf("\n");
        chushiqipan(qipan);

        // �ж���Ӯ
        if (panduan1shuying(qipan) == 1)
        {
            break;
        }
        if (pingju(qipan) == 1)
        {
            break;
        }

        // ���2����
        wanjia2luozi(qipan);
    }
    // ������Ϸ
    printf("��л����!\n");
    system("pause");
    return 0;
}