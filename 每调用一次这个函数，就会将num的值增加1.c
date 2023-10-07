#include <stdio.h>

 void plus1(float* n)
 {
    (*n)++;
    //这里要打括号，否则++优先级大于*。
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
