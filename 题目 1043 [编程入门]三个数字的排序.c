#include <stdio.h>

int main()
{
    int a;
    int b;
    int c;
    scanf("%d%d%d",&a,&b,&c);
    if (a<=b && a<=c)
    {
        if (b<=c)
            printf("%d %d %d",a,b,c);
        else
            printf("%d %d %d",a,c,b);
    }
    if (b<=a && b<=c)
    {
        if (a<=c)
            printf("%d %d %d",b,a,c);
        else
            printf("%d %d %d",b,c,a);
    }
    if (c<=b && c<=a)
    {
        if (a<=b)
            printf("%d %d %d",c,a,b);
        else
            printf("%d %d %d",c,b,a);
    }
    
    return 0;
}

/*  更简洁的代码
#include <stdio.h>

int main()
{
    int a, b, c;
    printf("请输入三个整数：");
    scanf("%d %d %d", &a, &b, &c);
    int smallest = a < b ? (a < c ? a : c) : (b < c ? b : c);
    int largest = a > b ? (a > c ? a : c) : (b > c ? b : c);
    int middle = a + b + c - smallest - largest;
    printf("排序后的结果为：%d %d %d\n", smallest, middle, largest);
    return 0;
}
*/