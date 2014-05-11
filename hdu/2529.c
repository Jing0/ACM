/*
 * =====================================================================================
 *
 *       Filename:  2529.c
 *
 *    Description:  
 *    Input
 *    多组测试数据
 *    每组测试数据包括3个浮点数h, l, v (1<=h<=2,1<=l<=100,0<v<=100),分别表示hhb的出手点高度，出手点离篮筐的水平距离和hhb投出的球的速度，h=l=v=0表示输入结束（球在运动过程中只受重力的作用，不受其它任何力的作用，重力加速度取g=9.8，题目中所有物理量均是国际单位制）
 *    Output
 *    对于每组数据，输出一行，包含一个数，在球可以投进篮筐的情况下，篮筐可以离地的最高高度（输入保证这个值一定大于0）。输出保留到2位小数。
 *    Sample Input
 *    1.5 5.0 7.0
 *    0 0 0
 *    Sample Output
 *    1.50
 *
 *        Created:  05/11/2014 10:29:50
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
int main(){
	double h,l,v;
	while(scanf("%lf%lf%lf",&h,&l,&v)!=EOF){
		if(!h&&!l&&!v)
			break;
		printf("%.2lf\n",h-l*l*9.8/(2*v*v)+v*v/(2*9.8));
	}
	return 0;
}