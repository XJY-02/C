#include <stdio.h>

 void plus1(float* n)
 {
    (*n)++;
    //����Ҫ�����ţ�����++���ȼ�����*��
 }

int main()
{
    float a = 0;
    int i;
    for ( i = 0; i < 10; i++)
    {
        plus1(&a);
        printf("%f\n",a);
    }
    return 0;
}
