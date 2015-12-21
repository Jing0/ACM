/*
 * =====================================================================================
 *
 *       Filename:  1284.c
 *
 *    Description:  
 *    在一个国家仅有1分，2分，3分硬币，将钱N兑换成硬币有很多种兑法。请你编程序计算出共有多少种兑法。
 *    Input
 *    每行只有一个正整数N，N小于32768。
 *    Output
 *    对应每个输入，输出兑换方法数。
 *    Sample Input
 *    2934
 *    12553
 *    Sample Output
 *    718831
 *    13137761
 *
 *        Created:  12/21/2015 20:01:10
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
int main(void) {
    int dp[32769] = {0};
    int i, j, k, n;
    dp[0] = 1;
    for (i = 1; i <= 3; i++) {
        for (j = i; j <= 32768; j++) {
            dp[j] = dp[j] + dp[j - i];
        }
    }
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", dp[n]);
    }
    return 0;
}
