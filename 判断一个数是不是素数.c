#include <stdio.h>

int is_sushu(int a)
{   
    int i;
    for( i = 2; i < a; i++)
    {
        if( a % i == 0)
            return 0;
    }
    return 1;
}

int main()
{   
    int i;
    for(i = 2; i <= 3000; i++)
        if ((is_sushu(i) * i) != 0)
            printf("%d ", is_sushu(i) * i);
    return 0;
}
