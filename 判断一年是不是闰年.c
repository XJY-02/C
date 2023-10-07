//闰年条件为： 能被四整除且不能被100整除 或者 能被400整除

#include <stdio.h>

int is_runnian(int a)
{   
    if ( a % 400 == 0)
        return 1;
    else if ( a % 4 == 0 && a % 100 != 0 )
        return 1;
    else
        return 0;
}

int main()
{   
    int i;
    for(i = 1900; i <=2300 ; i++)
        if ((is_runnian(i) * i) != 0)
            printf("%d ", is_runnian(i) * i);
    return 0;
}
