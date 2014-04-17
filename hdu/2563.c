/*
 * =====================================================================================
 *
 *       Filename:  2563.c
 *
 *    Description:  
 *    Problem Description
 *    在一无限大的二维平面中，我们做如下假设：
 *    1、  每次只能移动一格；
 *    2、  不能向后走（假设你的目的地是“向上”，那么你可以向左走，可以向右走，也可以向上走，但是不可以向下走）；
 *    3、  走过的格子立即塌陷无法再走第二次；
 *    求走n步不同的方案数（2种走法只要有一步不一样，即被认为是不同的方案）。
 *    Input
 *    首先给出一个正整数C，表示有C组测试数据
 *    接下来的C行，每行包含一个整数n (n<=20)，表示要走n步。
 *    Output
 *    请编程输出走n步的不同方案总数；
 *    每组的输出占一行。
 *    Sample Input
 *    2
 *    1
 *    2
 *    Sample Output
 *    3
 *    7
 *
 *        Created:  04/16/2014 21:40:19
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include<stdio.h>
int main(){
	int a[30],i,n,t;
	for(i=2,a[0]=3,a[1]=7;i<20;i++)
		a[i]=2*a[i-1]+a[i-2];
	while(scanf("%d",&n)!=EOF)
		while(n--){
			scanf("%d",&t);
			printf("%d\n",a[t-1]);
		}
	return 0;
}