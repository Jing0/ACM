/*
 * =====================================================================================
 *
 *       Filename:  3617.c
 *
 *    Description:  
 *    FJ is about to take his N (1 ≤ N ≤ 2,000) cows to the annual"Farmer of the Year" competition. In this contest every farmer arranges his cows in a line and herds them past the judges.
 *    The contest organizers adopted a new registration scheme this year: simply register the initial letter of every cow in the order they will appear (i.e., If FJ takes Bessie, Sylvia, and Dora in that order he just registers BSD). After the registration phase ends, every group is judged in increasing lexicographic order according to the string of the initials of the cows' names.
 *    FJ is very busy this year and has to hurry back to his farm, so he wants to be judged as early as possible. He decides to rearrange his cows, who have already lined up, before registering them.
 *    FJ marks a location for a new line of the competing cows. He then proceeds to marshal the cows from the old line to the new one by repeatedly sending either the first or last cow in the (remainder of the) original line to the end of the new line. When he's finished, FJ takes his cows for registration in this new order.
 *    Given the initial order of his cows, determine the least lexicographic string of initials he can make this way.
 *    Input
 *    * Line 1: A single integer: N
 *    * Lines 2..N+1: Line i+1 contains a single initial ('A'..'Z') of the cow in the ith position in the original line
 *    Output
 *    The least lexicographic string he can make. Every line (except perhaps the last one) contains the initials of 80 cows ('A'..'Z') in the new line.
 *    Sample Input
 *    6
 *    A
 *    C
 *    D
 *    B
 *    C
 *    B
 *    Sample Output
 *    ABCBCD
 *
 *        Created:  09/06/2015 17:44:36
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#define MAXN 2000+2
char str[MAXN], res[MAXN];
void solve(int n) {
	int i, cur, a, b, left;
	a = 0;
	b = n - 1;
	cur = 0;
	while (a <= b) {
		left = 0;
		for (i = 0; a + i <= b; ++i) {
			if (str[a + i] < str[b - i]) {
				left = 1;
				break;
			} else if (str[a + i] > str[b - i]) {
				left = 0;
				break;
			}
		}
		if (left) {
			res[cur++] = str[a++];
		} else {
			res[cur++] = str[b--];
		}
	}
}
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s", str + i);
	}
	solve(n);
	for (i = 0; i < n; ++i) {
		printf("%c", res[i]);
		if (i < n && (i + 1) % 80 == 0) {
			printf("\n");
		}
	}
	return 0;
}
