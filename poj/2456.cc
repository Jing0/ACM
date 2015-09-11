/*
 * =====================================================================================
 *
 *       Filename:  2456.cc
 *
 *    Description:  
 *    Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000). 
 *    His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
 *    Input
 *    * Line 1: Two space-separated integers: N and C 
 *    * Lines 2..N+1: Line i+1 contains an integer stall location, xi
 *    Output
 *    * Line 1: One integer: the largest minimum distance
 *    Sample Input
 *    5 3
 *    1
 *    2
 *    8
 *    4
 *    9
 *    Sample Output
 *    3
 *    Hint
 *    OUTPUT DETAILS: 
 *    FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3. 
 *    Huge input data,scanf is recommended.
 *
 *        Created:  09/11/2015 17:31:15
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <cstdio>
#include <algorithm>
#define MAX_N 100000+1
using namespace std;

const int INF = 100000000;
int n, c;
int x[MAX_N];
bool C(int d) {
	int last = 0;
	for (int i = 1; i < c; ++i) {
		int crt = last + 1;
		while (crt < n && x[crt] - x[last] < d) {
			++crt;
		}
		if (crt == n) {
			return false;
		}
		last = crt;
	}
	return true;
}
void solve() {
	sort(x, x + n);

	int lb = 0, ub = INF;
	while (ub - lb > 1) {
		int mid = (ub + lb) / 2;
		if (C(mid)) {
			lb = mid;
		} else {
			ub = mid;
		}
	}
	printf("%d\n", lb);
}
int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
	}
	solve();
	return 0;
}
