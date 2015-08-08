/*
 * =====================================================================================
 *
 *       Filename:  2084.c
 *
 *    Description:  
 *    在讲述DP算法的时候，一个经典的例子就是数塔问题，它是这样描述的：
 *    有如下所示的数塔，要求从顶层走到底层，若每一步只能走到相邻的结点，则经过的结点的数字之和最大是多少？
 *    已经告诉你了，这是个DP的题目，你能AC吗?
 *    Input
 *    输入数据首先包括一个整数C,表示测试实例的个数，每个测试实例的第一行是一个整数N(1 <= N <= 100)，表示数塔的高度，接下来用N行数字表示数塔，其中第i行有个i个整数，且所有的整数均在区间[0,99]内。
 *    Output
 *    对于每个测试实例，输出可能得到的最大和，每个实例的输出占一行。
 *    Sample Input
 *    1
 *    5
 *    7
 *    3 8
 *    8 1 0 
 *    2 7 4 4
 *    4 5 2 6 5
 *    Sample Output
 *    30
 *
 *        Created:  08/07/2015 16:42:09
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#define MAX(a,b) (a)>(b)?(a):(b)
#define MAX_LEN 103
int main(void) {
	int c, n, i, j, a[MAX_LEN][MAX_LEN];
	scanf("%d", &c);
	while (c--) {
		memset(a, -1, sizeof(a));
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			for (j = 0; j < i + 1; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		for (i = n - 1; i > 0; --i) {
			for (j = 0; j < i; ++j) {
				a[i-1][j] += MAX(a[i][j], a[i][j+1]);
			}
		}
		printf("%d\n", a[0][0]);
	}
	return 0;
}
