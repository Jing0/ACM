/*
 * =====================================================================================
 *
 *       Filename:  5578.c
 *
 *    Description:  
 *    N frogs from different countries are standing in a line. Each country is represented by a lowercase letter. The distance between adjacent frogs (e.g. the 1st and the 2nd frog, the N−1th and the Nth frog, etc) are exactly 1. Two frogs are friends if they come from the same country.
 *    The closest friends are a pair of friends with the minimum distance. Help us find that distance.
 *    Input
 *    First line contains an integer T, which indicates the number of test cases.
 *    Every test case only contains a string with length N, and the ith character of the string indicates the country of ith frogs.
 *    ⋅ 1≤T≤50.
 *    ⋅ for 80% data, 1≤N≤100.
 *    ⋅ for 100% data, 1≤N≤1000.
 *    ⋅ the string only contains lowercase letters.
 *    Output
 *    For every test case, you should output "Case #x: y", where x indicates the case number and counts from 1 and y is the result. If there are no frogs in same country, output −1 instead.
 *    Sample Input
 *    2
 *    abcecba
 *    abc
 *    Sample Output
 *    Case #1: 2
 *    Case #2: -1
 *    
 *
 *        Created:  12/07/2015 13:53:08
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int t, i;
    scanf("%d", &t);
    for (i = 0; i < t; ++i) {
        getchar();
        int ca[30];
        memset(ca, -1, sizeof(ca));
        int c, j = 0, min = 1024;
        while ((c = getchar()) != '\n') {
            int n = (int)(c - 'a');
            if (ca[n] != -1 && min > j - ca[n]) {
                min = j - ca[n];
            }
            ca[n] = j;
            ++j;
        }
        if (min == 1024) {
            min = -1;
        }
        printf("Case #%d: %d\n", i + 1, min);
    }
    return 0;
}
