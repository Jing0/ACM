/*
 * =====================================================================================
 *
 *       Filename:  1009.cc
 *
 *    Description:  
 *    FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food, JavaBean.
 *    The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food. FatMouse does not have to trade for all the JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans if he pays F[i]* a% pounds of cat food. Here a is a real number. Now he is assigning this homework to you: tell him the maximum amount of JavaBeans he can obtain.
 *    Input
 *    The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by two -1's. All integers are not greater than 1000.
 *    Output
 *    For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans that FatMouse can obtain.
 *    Sample Input
 *    5 3
 *    7 2
 *    4 3
 *    5 2
 *    20 3
 *    25 18
 *    24 15
 *    15 10
 *    -1 -1
 *    Sample Output
 *    13.333
 *    31.500
 *
 *        Created:  01/08/2016 09:38:07
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef struct {
	double rate;
	int no;
}Rate;
bool cmp (const Rate r1, const Rate r2) {
	return r1.rate > r2.rate;
}
int m, n;
int j[1001], f[1001];
Rate r[1001];
double calc() {
	double ans = 0;
	for (int i = 0; i < n && m; ++i) {
		int no = r[i].no;
		if (m >= f[no]) {
			ans += j[no];
			m -= f[no];
		} else {
			ans += j[no] * ((double)m / f[no]);
			m = 0;
		}
	}
	return ans;
}
int main() {
	while (scanf("%d%d", &m, &n) != EOF){
		if (m == -1 && n == -1) {
			break;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &j[i], &f[i]);
			r[i].rate = (double)j[i] / f[i];
			r[i].no = i;
		}
		sort(r, r + n, cmp);
		printf("%.3lf\n", calc());
	}
	return 0;
}
