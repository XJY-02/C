#include "game.h"

void menu1()
{
    printf("******************************\n");
    printf("*******      ɨ��     ********\n");
    printf("******   1. ��ʼ��Ϸ   *******\n");
    printf("******   2. �˳���Ϸ    ******\n");
    printf("******************************\n");
}

void again()
{
    printf("********************************\n");
    printf("*******   �Ƿ�����һ�֣�   *****\n");
    printf("*******   1. ����һ�ѣ�   ******\n");
    printf("*******   2. �˳���Ϸ     ******\n");
    printf("********************************\n");
}

void game()
{
    // �׵���Ϣ����
    //  1. ���úõ��׵���Ϣ
    char mine[ROWS][COLS] = {0}; // 11 * 11
    //  2. �Ų�����׵���Ϣ
    char show[ROWS][COLS] = {0};
    // ��ʼ��
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    // ��ӡ����
    DisplayBoard(show, ROW, COL);
    // ������
    SetMine(mine, ROW, COL);
    // DisplayBoard(mine, ROW, COL);//ȡ��ע�Ϳ��Կ���ʼ����ͼ��

    // ѡ����컹��ɨ��
    int input = 0;
    int new = 1;
    do
    {
        if (new) // �״�˵��
        {
            printf("\n  ˵����\n");
            printf("1.����1 2��ʾ��һ�еڶ���\n");
            printf("2.����0 0����ѡ���Ų黹�ǲ���\n");
            printf("3.������������Ա��Ų�\n\n");
            new = 0;
        }
        printf("��ѡ��1.�Ų� 2.����:>");
        scanf("%d", &input);
        int mistakeinput = 0;
        while ((getchar()) != '\n')
        {
            mistakeinput = 1;
        }
        if (mistakeinput)
        {
            printf("ѡ�����������ѡ��\n");
            continue;
        }

        int boom = 0;
        switch (input)
        {
        case 1:
            boom = FindMine(mine, show, ROW, COL); // ɨ��
            break;
        case 2:
            Flag_Planting(show, ROW, COL); // ����
            break;
        default:
            printf("ѡ�����������ѡ��\n");
            break;
        }

        // �ж���Ӯ

        // �䡪���ȵ�ը��
        if (boom)
        {
            break;
        }
        // Ӯ
        int i = 0;
        int j = 0;
        int opened_num = 0;
        for (i = 1; i <= ROW; i++)
        {
            for (j = 1; j <= COL; j++)
            {
                if (show[i][j] != '*' && show[i][j] != 'X')
                {
                    opened_num++;
                }
            }
        }
        if (opened_num == ROW * COL - EASY_COUNT)
        {
            DisplayBoard(mine, ROW, COL);
            printf("��ϲ�㣬���׳ɹ���<(�����)>\n");
            break;
        }
    } while (1);
}

void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    int new = 1;
    do
    {
        if (new)
        {
            menu1();
            new = 0;
        }
        else
        {
            again();
        }
        printf("��ѡ��:>");
        scanf("%d", &input);

        int mistakeinput = 0;
        while ((getchar()) != '\n')
        {
            mistakeinput = 1;
        }
        if (mistakeinput)
        {
            printf("ѡ�����������ѡ��\n");
            new = 1;
            continue;
        }

        switch (input)
        {
        case 1:
            game();
            break;
        case 2:
            printf("�˳���Ϸ\n");
            break;
        default:
            printf("ѡ�����������ѡ��\n");
            new = 1;
            break;
        }

    } while (input != 2);
}

int main()
{
    test();
    system("pause");
    return 0;
}