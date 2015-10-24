/*
 * =====================================================================================
 *
 *       Filename:  5494.c
 *
 *    Description:  
 *    Soda and Beta are good friends. They are going to play a card game today. Soda has n cards with number a1,a2,...,an while Beta has n cards with number b1,b2,...,bn.
 *    First, they choose a number m no larger than n. Then they both randomly select m cards from their own n cards. The one with larger sum of the selected cards will win. Soda wants to know if he can always win no mater what cards will be randomly selected from him and Beta.
 *    Input
 *    There are multiple test cases. The first line of input contains an integer T(1≤T≤100), indicating the number of test cases. For each test case:
 *    The first line contains two integer n and m (1≤m≤n≤500). The second line contains n integers a1,a2,...,an (1≤ai≤1000) denoting Soda's cards. The third line contains n integers b1,b2,...,bn (1≤bi≤1000) denoting Beta's cards.
 *    Output
 *    For each test case, output "YES" (without the quotes) if Soda can always win, otherwise output "NO" (without the quotes) in a single line.
 *    Sample Input
 *    2
 *    3 1
 *    4 5 6
 *    1 2 3
 *    5 2
 *    3 4 7 8 9
 *    3 4 5 2 3
 *    Sample Output
 *    YES
 *    NO
 *
 *        Created:  10/24/2015 15:07:57
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 500
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int main(int argc, char const *argv[]) {
    int t, i, m, n, a[MAX_N + 1], b[MAX_N + 1], suma, sumb;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }
        qsort(a, n, sizeof(int), cmp);
        qsort(b, n, sizeof(int), cmp);
        for (suma = 0, i = 0; i < m; ++i) {
            suma += a[i];
        }
        for (sumb = 0, i = 0; i < m; ++i) {
            sumb += b[n - 1 - i];
        }
        printf("%s\n", suma > sumb ? "YES" : "NO");
    }
    return 0;
}
