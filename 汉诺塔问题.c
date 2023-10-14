/* 问题背景
汉诺塔问题是一个经典的问题。
汉诺塔（Hanoi Tower），又称河内塔，源于印度一个古老传说。
大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。
大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。
并且规定，任何时候，在小圆盘上都不能放大圆盘，且在三根柱子之间一次只能移动一个圆盘。
问应该如何操作？ 

假设A柱有n片，B、C没有。要求把n片全部转移到C柱
*/

/* 代码实现的思路主要分为三步：
假设总共需要从A到C柱移动n个盘子
1.将A柱上的n-1个盘子移向B柱
2.将A柱上仅剩的最后一个盘子移向C柱
3.将B柱上的n-1个盘子移向C柱 */

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


void move(char x, char y)
{   
    static int count = 1;
	printf("%d. 将 %c柱 上的一个盘子转移到 %c柱\n",count,x,y);
    count++;
}
void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		move(a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);//将A座上的n-1个盘子借助C座移向B座
		move(a, c);//将A座上最后一个盘子移向C座
		hanoi(n - 1, b, a, c);//将B座上的n-1个盘子借助A座移向C座
	} 
}
//move中的实参与hanoi函数中的形参相对应，而hanoi函数中形参a，b，c所对应的值也是在有规律的变化
int main()
{
	int n = 0;
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
