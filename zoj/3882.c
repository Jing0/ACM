/*
 * =====================================================================================
 *
 *       Filename:  3882.c
 *
 *    Description:  
 *    There is a game very popular in ZJU at present, Bob didn't meant to participate in it. But he decided to join it after discovering a lot of pretty girls playing it.
 *    There are n stones on the ground and they are marked as 1 to n respectively. There will be 2 players in each competition. And the game rules are simple, A and B take turns to move. Each round, one of them can only take 1 number away, and then pick out all the divisors of the choosed number. When anyone who can not take away 1 number any longer, he will fail the whole game.
 *    Input
 *    There are multiple cases. Each case include an integer number n (0 ≤ n ≤ 100).
 *    Output
 *    For each case, A win, output "win". If not, output"fail".
 *    Sample Input1
 *    3
 *    4
 *    Sample Output1
 *    win
 *    win
 *
 *        Created:  08/04/2015 11:53:40
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%s\n", n==0?"fail":"win");
	}
	return 0;
}
