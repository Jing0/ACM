/*
 * =====================================================================================
 *
 *       Filename:  1673.c
 *
 *    Description:  
 *    When shopping on Long Street, Michael usually parks his car at some random location, and then walks to the stores he needs.
 *    Can you help Michael choose a place to park which minimises the distance he needs to walk on his shopping round?
 *    Long Street is a straight line, where all positions are integer.
 *    You pay for parking in a specific slot, which is an integer position on Long Street. Michael does not want to pay for more than one parking though. He is very strong, and does not mind carrying all the bags around.
 *    Input
 *    The first line of input gives the number of test cases, 1 <= t <= 100. There are two lines for each test case. The first gives the number of stores Michael wants to visit, 1 <= n <= 20, and the second gives their n integer positions on Long Street, 0 <= xi <= 99.
 *    Output
 *    Output for each test case a line with the minimal distance Michael must walk given optimal parking.
 *    Sample Input
 *    2
 *    4
 *    24 13 89 37
 *    6
 *    7 30 41 14 39 42
 *    Sample Output
 *    152
 *    70
 *
 *        Created:  08/05/2015 15:13:58
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main(void) {
	int t, n, i, sum, a[22];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		qsort(a, n, sizeof(int), cmp);
		sum = 0;
		for (i = 1; i < n; ++i) {
			sum += a[i] - a[i - 1];
		}
		printf("%d\n", sum * 2);
	}
	return 0;
}
