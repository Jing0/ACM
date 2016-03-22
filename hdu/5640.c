/*
 * =====================================================================================
 *
 *       Filename:  5640.c
 *
 *    Description:  
 *    It is the king's birthday before the military parade . The ministers prepared a rectangle cake of size n×m(1≤n,m≤10000) . The king plans to cut the cake himself. But he has a strange habit of cutting cakes. Each time, he will cut the rectangle cake into two pieces, one of which should be a square cake.. Since he loves squares , he will cut the biggest square cake. He will continue to do that until all the pieces are square. Now can you tell him how many pieces he can get when he finishes.
 *    Input
 *    The first line contains a number T(T≤1000), the number of the testcases.
 *    For each testcase, the first line and the only line contains two positive numbers n,m(1≤n,m≤10000).
 *    Output
 *    For each testcase, print a single number as the answer.
 *    Sample Input
 *    2
 *    2 3
 *    2 5
 *    Sample Output
 *    3
 *    4
 *    
 *        Created:  03/23/2016 00:10:10
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#define swap(a,b) {a=a+b;b=a-b;a=a-b;} 
int main() {
	int t, n, m, cnt;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		if (n > m) {
			swap(n, m);
		}
		cnt = 0;
		while (m % n != 0) {
			int tmp = m / n;
			m -= tmp * n;
			if (n > m) {
				swap(n, m);
			}
			cnt += tmp;
		}
		cnt += m / n;
		printf("%d\n", cnt);
	}
	return 0;
}
