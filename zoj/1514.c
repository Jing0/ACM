/*
 * =====================================================================================
 *
 *       Filename:  1514.c
 *
 *    Description:  
 *    Your school organized a big party to celebrate your team brilliant win in the prestigious, worldfamous ICPC (International Collegiate Poetry Contest). Everyone in your school was invited for an evening which included cocktail, dinner and a session where your team work was read to the audience. The evening was a success - many more people than you expected showed interested in your poetry - although some critics of yours said it was food rather than words that attracted such an audience.
 *    Whatever the reason, the next day you found out why the school hall had seemed so full: the school director confided he had discovered that several of the tickets used by the guests were fake. The real tickets were numbered sequentially from 1 to N (N <= 10000). The director suspects some people had used the school scanner and printer from the Computer Room to produce copies of the real tickets. The director gave you a pack with all tickets collected from the guests at the party's entrance, and asked you to determine how many tickets in the pack had 'clones', that is, another ticket with the same sequence number.
 *    Input
 *    The input contains data for several test cases. Each test case has two lines. The first line contains two integers N and M which indicate respectively the number of original tickets and the number of persons attending the party (1 <= N <= 10000 and 1 <= M <= 20000). The second line of a test case contains M integers Ti representing the ticket numbers in the pack the director gave you (1 <= Ti <= N). The end of input is indicated by N = M = 0.
 *    Output
 *    For each test case your program should print one line, containing the number of tickets in the pack that had another ticket with the same sequence number.
 *    Sample Input
 *    5 5
 *    3 3 1 2 4
 *    6 10
 *    6 1 3 6 6 4 2 3 1 2
 *    0 0
 *    Sample Output
 *    1
 *    4
 *
 *        Created:  08/06/2015 11:52:23
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#define MAX 10002
int main(void) {
	int n, m, tmp, i, a[MAX], count;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (!n && !m) {
			break;
		}
		count = 0;
		memset(a, 0, MAX);
		for (i = 0; i < m; ++i) {
			scanf("%d", &tmp);
			if (!a[tmp]) {
				a[tmp] = 1;
			} else if(a[tmp] == 1) {
				a[tmp] = 2;
				++count;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
