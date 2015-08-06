/*
 * =====================================================================================
 *
 *       Filename:  1539.c
 *
 *    Description:  
 *    Out of N soldiers, standing in one line, it is required to choose several to send them scouting. 
 *    In order to do that, the following operation is performed several times: if the line consists of more than three soldiers, then all soldiers, standing on even positions, or all soldiers, standing on odd positions, are taken away. The above is done until three or less soldiers are left in the line. They are sent scouting. Find, how many different groups of three scouts may be created this way.
 *    Note: Groups with less than three number of soldiers are not taken into consideration.
 *    0 < N <= 10 000 000
 *    Input
 *    The input file contains the number N.
 *    Process to the end of file.
 *    Output
 *    The output file must contain the solution - the amount of variants.
 *    Sample Input
 *    10
 *    4
 *    Sample Output
 *    2
 *    0
 *
 *        Created:  08/06/15 14:59:09
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000003
int main(void) {
	long i, n;
	int *a = malloc(MAX*sizeof(int));
	a[1] = 0;
	a[2] = 0;
	a[3] = 1;
	for (i = 4; i < MAX - 1; ++i) {
		a[i] = a[i / 2] + a[i - i / 2];
	}
	while (scanf("%ld", &n) != EOF) {
		printf("%d\n", a[n]);
	}
	return 0;
}
