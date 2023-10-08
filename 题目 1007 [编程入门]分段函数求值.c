#include <stdio.h>

int main()
{
    float x;
    float y;
    scanf("%f",&x);
    if (x<1)
        y = x;
    if (x>=1 && x<10)
        y = 2*x - 1;
    if (x>=10)
        y = 3*x - 11;
    printf("%f",y);
    return 0;
}
