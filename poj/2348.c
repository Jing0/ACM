/*
 * =====================================================================================
 *
 *       Filename:  2348.c
 *
 *    Description:  
 *    Two players, Stan and Ollie, play, starting with two natural numbers. Stan, the first player, subtracts any positive multiple of the lesser of the two numbers from the greater of the two numbers, provided that the resulting number must be nonnegative. Then Ollie, the second player, does the same with the two resulting numbers, then Stan, etc., alternately, until one player is able to subtract a multiple of the lesser number from the greater to reach 0, and thereby wins. For example, the players may start with (25,7): 
 *    25 7
 *    11 7
 *    4 7
 *    4 3
 *    1 3
 *    1 0
 *    an Stan wins.
 *    Input
 *    The input consists of a number of lines. Each line contains two positive integers giving the starting two numbers of the game. Stan always starts.
 *    Output
 *    For each line of input, output one line saying either Stan wins or Ollie wins assuming that both of them play perfectly. The last line of input contains two zeroes and should not be processed.
 *    Sample Input
 *    34 12
 *    15 24
 *    0 0
 *    Sample Output
 *    Stan wins
 *    Ollie wins
 *
 *        Created:  08/08/2015 23:30:14
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#define swap(a,b) (a)+=(b);(b)=(a)-(b);(a)-=(b);
int main(void) {
	long a, b, flag;
	while (scanf("%ld%ld", &a, &b) !=EOF) {
		if (!a && !b) {
			break;
		}
		flag = 1;
		while (1) {
			if (a > b) {
				swap(a, b);
			}
			if (b % a == 0) {
				break;
			}
			/* b > 2 * a 可能会超过范围 */
			if (b - a > a) {
				break;
			}
			b -= a;
			flag = !flag;
		}
		printf("%s wins\n", flag ? "Stan" : "Ollie");
	}
	return 0;
}
