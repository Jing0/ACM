/*
 * =====================================================================================
 *
 *       Filename:  2002.c
 *
 *    Description:  
 *    Problem Description
 *    根据输入的半径值，计算球的体积。
 *    Input
 *    输入数据有多组，每组占一行，每行包括一个实数，表示球的半径。
 *
 *    Output
 *    输出对应的球的体积，对于每组输入数据，输出一行，计算结果保留三位小数。
 *
 *    Sample Input
 *    1
 *    1.5
 *
 *    Sample Output
 *    4.189
 *    14.137
 *
 *    Hint
 *    #define PI 3.1415927
 *
 *        Version:  1.0
 *        Created:  04/07/2014 23:16:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#define PI 3.1415927
int main(){
	double r,v;
	while(scanf("%lf",&r)!=EOF){
		v=4*PI*r*r*r/3;
		printf("%.3lf\n",v);
	}
	return 0;
}
