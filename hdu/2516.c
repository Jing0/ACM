/*
 * =====================================================================================
 *
 *       Filename:  2516.c
 *
 *    Description:  
 *    1堆石子有n个,两人轮流取.先取者第1次可以取任意多个，但不能全部取完.以后每次取的石子数不能超过上次取子数的2倍。取完者胜.先取者负输出"Second win".先取者胜输出"First win".
 *    Input
 *    输入有多组.每组第1行是2<=n<2^31. n=0退出.
 *    Output
 *    先取者负输出"Second win". 先取者胜输出"First win". 
 *    参看Sample Output.
 *    Sample Input
 *    2
 *    13
 *    10000
 *    0
 *    Sample Output
 *    Second win
 *    Second win
 *    First win
 *
 *        Created:  08/06/2015 16:28:53
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#define MAX 50
int main(void) {
	long a[MAX] = {1, 1}, i, n;
	for (i = 2; i < MAX; ++i) {
		a[i] = a[i - 1] + a[i - 2];
	}
	while (scanf("%ld", &n) != EOF) {
		if (!n) {
			break;
		}
		for (i = 0; i < MAX && a[i] < n; ++i){;}
		printf("%s win\n", (a[i] == n) ? "Second" : "First");
	}
	return 0;
}
