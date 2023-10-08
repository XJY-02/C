//给出一个不多于5位的整数，
//要求 1、求出它是几位数 
//2、分别输出每一位数字 
//3、按逆序输出各位数字，例如原数为321,应输出123

#include <stdio.h>
#include <math.h>

int main()
{   
    int a;
    scanf("%d",&a);
    int i;
    int weishu = 0;
    int a1 = a / 10000;
    int a2 = (a - a1*10000) / 1000;
    int a3 = (a - a1*10000 - a2*1000)/ 100;
    int a4 = (a - a1*10000 - a2*1000 - a3*100)/ 10;
    int a5 = (a - a1*10000 - a2*1000 - a3*100 - a4*10) /1;
    int arr[] = {a1,a2,a3,a4,a5};

    for(i = 0; i < 5; i++)
    {
        if(a >= pow(10,i))
            weishu++;
    }
    printf("%d\n",weishu);

    int s = 0;
    for (i=0;i<5;i++)
    {   
        if(arr[i] != 0)
            s = 1;
        if(arr[i] != 0 || s == 1)
        {
            printf("%d",arr[i]);
            if (i<4)
                printf(" ");
        }
    }
    printf("\n");
    for (i = 4 ; i > 4 - weishu; i--)
        printf("%d",arr[i]);
    return 0;
}

/* 更好的算法
#include<stdio.h>

int main()
{

	int a[4],t,n,count=0,i=0;
	scanf("%d",&t);
	n=t;
	while(t)
	{
		a[count]=t%10;
		t/=10;
		count++;
	}
	printf("%d\n",count);
	for(i=count-1;i>0;i--)
	{
		printf("%d ",a[i]);
	}
	printf("%d\n",a[0]);
	
	while(n)
	{
		printf("%d",n%10);
		n=n/10;
	 } 
		
	return 0;
}
*/