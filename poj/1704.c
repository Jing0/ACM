/*
 * =====================================================================================
 *
 *       Filename:  1704.c
 *
 *    Description:  
 *    Georgia and Bob decide to play a self-invented game. They draw a row of grids on paper, number the grids from left to right by 1, 2, 3, ..., and place N chessmen on different grids, as shown in the following figure for example: 
 *    Georgia and Bob move the chessmen in turn. Every time a player will choose a chessman, and move it to the left without going over any other chessmen or across the left edge. The player can freely choose number of steps the chessman moves, with the constraint that the chessman must be moved at least ONE step and one grid can at most contains ONE single chessman. The player who cannot make a move loses the game. 
 *    Georgia always plays first since "Lady first". Suppose that Georgia and Bob both do their best in the game, i.e., if one of them knows a way to win the game, he or she will be able to carry it out. 
 *    Given the initial positions of the n chessmen, can you predict who will finally win the game? 
 *    Input
 *    The first line of the input contains a single integer T (1 <= T <= 20), the number of test cases. Then T cases follow. Each test case contains two lines. The first line consists of one integer N (1 <= N <= 1000), indicating the number of chessmen. The second line contains N different integers P1, P2 ... Pn (1 <= Pi <= 10000), which are the initial positions of the n chessmen.
 *    Output
 *    For each test case, prints a single line, "Georgia will win", if Georgia will win the game; "Bob will win", if Bob will win the game; otherwise 'Not sure'.
 *    Sample Input
 *    2
 *    3
 *    1 2 3
 *    8
 *    1 5 6 7 9 12 14 17
 *    Sample Output
 *    Bob will win
 *    Georgia will win
 *
 *        Created:  08/10/2015 11:14:30
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10005

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}
int main(void) {
	int t, a[MAX], i, n, res;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		if (n % 2 == 1) {
			a[n++] = 0;
		}
		qsort(a, n, sizeof(int), cmp);
		res = 0;
		for (i = 0; i + 1 < n; i += 2) {
			res ^= a[i + 1] - a[i] - 1;
		}
		printf("%s will win\n", res ? "Georgia" : "Bob");
	}
	return 0;
}
