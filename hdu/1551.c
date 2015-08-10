/*
 * =====================================================================================
 *
 *       Filename:  1551.c
 *
 *    Description:  
 *    Inhabitants of the Wonderland have decided to hold a regional programming contest. The Judging Committee has volunteered and has promised to organize the most honest contest ever. It was decided to connect computers for the contestants using a "star" topology - i.e. connect them all to a single central hub. To organize a truly honest contest, the Head of the Judging Committee has decreed to place all contestants evenly around the hub on an equal distance from it.
 *    To buy network cables, the Judging Committee has contacted a local network solutions provider with a request to sell for them a specified number of cables with equal lengths. The Judging Committee wants the cables to be as long as possible to sit contestants as far from each other as possible.
 *    The Cable Master of the company was assigned to the task. He knows the length of each cable in the stock up to a centimeter, and he can cut them with a centimeter precision being told the length of the pieces he must cut. However, this time, the length is not known and the Cable Master is completely puzzled.
 *    You are to help the Cable Master, by writing a program that will determine the maximal possible length of a cable piece that can be cut from the cables in the stock, to get the specified number of pieces.
 *    Input
 *    The input consists of several testcases. The first line of each testcase contains two integer numbers N and K, separated by a space. N (1 ≤ N ≤ 10000) is the number of cables in the stock, and K (1 ≤ K ≤ 10000) is the number of requested pieces. The first line is followed by N lines with one number per line, that specify the length of each cable in the stock in meters. All cables are at least 1 centimeter and at most 100 kilometers in length. All lengths in the input are written with a centimeter precision, with exactly two digits after a decimal point.
 *    The input is ended by line containing two 0's.
 *    Output
 *    For each testcase write to the output the maximal length (in meters) of the pieces that Cable Master may cut from the cables in the stock to get the requested number of pieces. The number must be written with a centimeter precision, with exactly two digits after a decimal point.
 *    If it is not possible to cut the requested number of pieces each one being at least one centimeter long, then the output must contain the single number "0.00" (without quotes).
 *    Sample Input
 *    4 11
 *    8.02
 *    7.43
 *    4.57
 *    5.39
 *    0 0
 *    Sample Output
 *    2.00
 *
 *        Created:  08/10/2015 15:12:32
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <math.h>
#define INF 100010
int k, n;
double a[10002];
int c(double x) {
    int i, num = 0;
    for (i = 0; i < n; ++i) {
        num += (int)(a[i] / x);
    }
    return num >= k;
}
int main(void) {
    int i;
    while (scanf("%d%d", &n, &k) != EOF) {
        if (!n && !k) {
            break;
        }
        for (i = 0; i < n; ++i) {
            scanf("%lf", &a[i]);
        }
        double l = 0, u = INF, mid;
        for (i = 0; i < 200; ++i) {
            mid = (l + u)/2;
            if (c(mid)) {
                l = mid;
            } else {
                u = mid;
            }
        }
        printf("%.2lf\n", floor(u * 100)/100);
    }
    return 0;
}
