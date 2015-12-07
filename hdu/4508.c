/*
 * =====================================================================================
 *
 *       Filename:  4508.c
 *
 *    Description:  
 *    Input
 *    　　输入包含多组测试用例。
 *    　　每组数据以一个整数n开始，表示每天的食物清单有n种食物。 
 *    　　接下来n行，每行两个整数a和b，其中a表示这种食物可以带给湫湫的幸福值（数值越大，越幸福），b表示湫湫吃这种食物会吸收的卡路里量。
 *    　　最后是一个整数m，表示湫湫一天吸收的卡路里不能超过m。
 *    　　[Technical Specification]
 *    　　1. 1 <= n <= 100
 *    　　2. 0 <= a,b <= 100000
 *    　　3. 1 <= m <= 100000
 *    Output
 *    　　对每份清单，输出一个整数，即满足卡路里吸收量的同时，湫湫可获得的最大幸福值。
 *    Sample Input
 *    3
 *    3 3
 *    7 7
 *    9 9
 *    10
 *    5
 *    1 1
 *    5 3
 *    10 3
 *    6 8
 *    7 5
 *    6
 *    Sample Output
 *    10
 *    20
 *
 *        Created:  12/07/2015 16:25:31
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#define max(a,b)(a>b?a:b)
int n, m;
int dp[100008];
int a[108], b[108];
void compete(int v, int w)
{
	int i;
	for (i = w; i <= m; i++) {
		dp[i] = max(dp[i], dp[i - w] + v);
	}
}
int main(void)
{
    while (scanf("%d", &n) != EOF)
    {
        int i;
        memset(dp, 0, sizeof(dp));
        for (i = 1; i <= n; i++) {
            scanf("%d%d", &a[i], &b[i]);
		}
        scanf("%d", &m);
        for (i = 1; i <= n; i++) {
            compete(a[i], b[i]);
		}
        printf("%d\n", dp[m]);
    }
}
