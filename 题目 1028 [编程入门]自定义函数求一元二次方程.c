/*
��Ŀ����
�󷽳� a*x^2 + b*x + c = 0 �ĸ��������������ֱ���b^2-4ac����0������0����С��0ʱ�ĸ�������������������������a��b��c��ֵ��
�����ʽ
a b c
�����ʽ
x1=? x2=?
��������
4 1 1
�������
x1=-0.125+0.484i x2=-0.125-0.484i
*/

#include <stdio.h>
#include <math.h>

// b^2-4ac����0ʱ
void dayu0(float a, float b, float c)
{
    float panbieshi = pow(b, 2) - 4 * a * c;
    float x1 = (-b + sqrt(panbieshi)) / (2 * a);
    float x2 = (-b - sqrt(panbieshi)) / (2 * a);
    printf("x1=%.3f x2=%.3f", x1, x2);
}

// b^2-4ac����0ʱ
void dengyu0(float a, float b, float c)
{
    float panbieshi = pow(b, 2) - 4 * a * c;
    float x1 = (-b + sqrt(panbieshi)) / (2 * a);
    float x2 = (-b - sqrt(panbieshi)) / (2 * a);
    printf("x1=%.3f x2=%.3f", x1, x2);
}

// b^2-4acС��0ʱ
void xiaoyu0(float a, float b, float c)
{

    float panbieshi = pow(b, 2) - 4 * a * c;
    float x1shibu = (-b) / (2 * a), x2shibu = (-b) / (2 * a);
    float x1xubu = (sqrt(-panbieshi)) / (2 * a), x2xubu = (sqrt(-panbieshi)) / (2 * a);
    printf("x1=%.3f+%.3fi x2=%.3f-%.3fi", x1shibu, x1xubu, x2shibu, x2xubu);
}

int main()
{
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    float panbieshi = pow(b, 2) - 4 * a * c;
    if (panbieshi > 0)
    {
        dayu0(a, b, c);
    }
    else if (panbieshi == 0)
    {
        dengyu0(a, b, c);
    }
    else if (panbieshi < 0)
    {
        xiaoyu0(a, b, c);
    }
    return 0;
}