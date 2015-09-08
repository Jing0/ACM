/*
 * =====================================================================================
 *
 *       Filename:  5387.c
 *
 *    Description:  
 *    Give a time.(hh:mm:ss)，you should answer the angle between any two of the minute.hour.second hand
 *    Notice that the answer must be not more 180 and not less than 0
 *
 *    Input
 *    There are T(1≤T≤104) test cases
 *    for each case,one line include the time
 *    0≤hh<24,0≤mm<60,0≤ss<60
 *
 *    Output
 *    for each case,output there real number like A/B.(A and B are coprime).if it's an integer then just print it.describe the angle between hour and minute,hour and second hand,minute and second hand.
 *
 *    Sample Input
 *    4
 *    00:00:00
 *    06:00:00
 *    12:54:55
 *    04:40:00
 *
 *    Sample Output
 *    0 0 0 
 *    180 180 0 
 *    1391/24 1379/24 1/2 
 *    100 140 120 
 *
 *        Created:  09/08/2015 23:40:49
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
void printAns(int s, int m) {
	if (s % m == 0) {
		printf("%d ", s / m);
	} else {
		int gcdt = gcd(s, m);
		printf("%d/%d ", s/gcdt, m/gcdt);
	}
}
int main() {
	int t, hour, min, sec;
	scanf("%d", &t);
	while (t--) {
		scanf("%d:%d:%d", &hour, &min, &sec);
		hour %= 12;
		int a = abs(3600 * hour - 660 * min - 11 * sec);
		if (a > 21600) {
			a = 43200 - a;
		}
		printAns(a, 120);
		int b = abs(3600 * hour + 60 * min - 719 * sec);
		if (b > 21600) {
			b = 43200 - b;
		}
		printAns(b, 120);
		int c = abs(59 * sec - 60 * min);
		if (c > 1800) {
			c = 3600 - c;
		}
		printAns(c, 10);
		printf("\n");
	}
	return 0;
}

