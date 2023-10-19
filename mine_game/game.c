#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int rows, int cols)
{
    int i = 0;
    int j = 0;
    // ��ӡ�к�
    printf("    ");
    for (i = 1; i <= cols; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    printf("  ");
    for (i = 0; i <= cols; i++)
    {
        if (i < 10)
        {
            printf("--");
        }
        else
        {
            printf("---");
        }
    }
    printf("\n");
    for (i = 1; i <= rows; i++)
    {
        printf("%d", i); // ��ӡ�к�
        if (i < 10)
        {
            printf(" ");
        }
        printf("|");
        for (j = 1; j <= cols; j++)
        {
            if (j >= 10)
            {
                printf(" ");
            }

            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

void SetMine(char board[ROWS][COLS], int rows, int cols)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % rows + 1; // 1~9
        int y = rand() % cols + 1; // 1~9
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

char Get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    int count = 0;
    int i = 0;
    int j = 0;
    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            if (mine[i][j] == '1')
            {
                count++;
            }
        }
    }

    return count + '0';
}

int Check_if_there_are_any_unchecked_areas_around(char show[ROWS][COLS], int x, int y)
{
    int i = 0;
    int j = 0;
    int result = 0;
    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            if (show[i][j] == '*')
            {
                result = 1;
            }
        }
    }
    return result;
}

void Check_adjacent_coordinates(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
    int i = 0;
    int j = 0;
    // �㿪��Χ8������
    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            if (show[i][j] == '*' && (i != x || j != y))
            {
                show[i][j] = Get_mine_count(mine, i, j);
            }
        }
    }
    for (i = x - 1; i <= x + 1; i++) // ������3��
    {
        for (j = y - 1; j <= y + 1; j++) // ����������
        {
            if (i != x || j != y) // ������Χ�����꣨����Ҳ����Χ��û���㿪�ĸ��ӵ����꣬���Բ��Ӹ������ƣ����Ǽ��˿��Լ�������ʱ�䣩
            {
                if (show[i][j] == '0') // ������Χû�е��׵�����
                {
                    if (i >= 1 && i <= COL && j >= 1 && j <= COL) // �������ڵ�����
                    {
                        if (Check_if_there_are_any_unchecked_areas_around(show, i, j)) // ��Χ��û���㿪�ĸ��ӵ�����
                        {
                            Check_adjacent_coordinates(mine, show, i, j);
                        }
                    }
                }
            }
        }
    }
}

int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
    int x = 0;
    int y = 0;
    int mistake = 0;
    int sure = 0;
    do
    {
        int mistake = 0;
        printf("�������Ų������:>");
        scanf("%d%d", &x, &y);
        // ����Ƿ�ʱ
        while ((getchar()) != '\n')
        {
            mistake = 1;
        }
        if (x == 0 && y == 0 && mistake == 0) // ����ѡ��
        {
            break;
        }
        if (x < 1 || x > rows || y < 1 || y > cols)
        {

            mistake = 1;
        }
        if (mistake)
        {
            printf("����Ƿ�������������\n"); // �Ƿ���Χ
            continue;
        }
        // ����Ϸ�ʱ

        if (show[x][y] != '*' && show[x][y] != 'X')
        {
            printf("�Ѿ��Ų��������\n");
            continue;
        }

        if (show[x][y] == 'X') // ������λ��
        {
            do
            {
                printf("�Ƿ�ȷ���Ų������λ�ã�\n1.�� 2.��:>");
                scanf("%d", &sure);
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
                if (sure == 1 || sure == 2)
                {
                    break;
                }
                else
                {
                    printf("ѡ�����������ѡ��\n");
                }
            } while (1);
        }
        if (sure == 2)
        {
            continue;
        }

        if (mine[x][y] == '1') // �ȵ���
        {
            DisplayBoard(mine, ROW, COL);
            printf("�㱻ը���˨i�n�i \n����һ�ΰɣ�\n");
            return 1;
        }

        // û�вȵ��ף�Ҳ��������λ��
        show[x][y] = Get_mine_count(mine, x, y);
        if (show[x][y] == '0') // �����������Χ8��û����
        {
            Check_adjacent_coordinates(mine, show, x, y); // չ���Ų���Χ8��
        }
        DisplayBoard(show, ROW, COL);
        break;
    } while (1);
    return 0;
}

void Flag_Planting(char show[ROWS][COLS], int rows, int cols)
{
    int x = 0;
    int y = 0;
    int mistake = 0;
    do
    {
        int mistake = 0;
        printf("��������������:>");
        scanf("%d%d", &x, &y);
        // ����Ƿ�ʱ
        while ((getchar()) != '\n')
        {
            mistake = 1;
        }
        if (x == 0 && y == 0 && mistake == 0) // ����ѡ��
        {
            break;
        }
        if (x < 1 || x > rows || y < 1 || y > cols)
        {

            mistake = 1;
        }
        if (mistake)
        {
            printf("����Ƿ�������������\n"); // �Ƿ���Χ
            continue;
        }
        // ����Ϸ�ʱ
        if (show[x][y] != '*') // ���������Ų�
        {
            if (show[x][y] == 'X')
            {
                printf("��������������\n");
            }
            else
            {
                printf("�Ѿ��Ų��������\n");
            }
            continue;
        }
        else
        {
            show[x][y] = 'X';
            DisplayBoard(show, ROW, COL);
            break;
        }
    } while (1);
}