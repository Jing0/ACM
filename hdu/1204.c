/*
 * =====================================================================================
 *
 *       Filename:  1204.c
 *
 *    Description:  
 *    生日Party结束的那天晚上，剩下了一些糖果，Gandon想把所有的都统统拿走，Speakless于是说：“可以是可以，不过我们来玩24点，你不是已经拿到了一些糖果了吗？这样，如果谁赢一局，就拿走对方一颗糖，直到拿完对方所有的糖为止。”如果谁能算出来而对方算不出来，谁就赢，但是如果双方都能算出或者都不能，就算平局，不会有任何糖果的得失。 
 *    Speakless是个喜欢提前想问题的人，既然他发起了这场糖果大战，就自然很想赢啦（不然可就要精光了-_-）。现在他需要你的帮忙，给你他每局赢的概率和Gardon每局赢的概率，请你给出他可能获得这场大战胜利的概率。
 *    Input
 *    每行有四个数，Speakless手上的糖果数N、Gardon手上的糖果数M(0<=N,M<=50)、一局Speakless能解答出来的概率p、一个问题Gardon能解答出来的概率q(0<=p,q<=1)。
 *    Output
 *    每行一个数，表示Speakless能赢的概率（用百分比计算，保留到小数点后2位）。
 *    Sample Input
 *    50 50 0.5 0.5
 *    10 10 0.51 0.5
 *    50 50 0.51 0.5
 *    Sample Output
 *    0.50
 *    0.60
 *    0.88
 *
 *        Created:  08/06/2015 17:33:37
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <math.h>
int main(void) {
	int n,m;
	double p, q, t;
	while (scanf("%d%d%lf%lf", &n, &m, &p, &q) != EOF) {
		if (m == 0) {
			printf("1.00\n");
		} else if (n == 0) {
			printf("0.00\n");
		} else {
			t = q * (1 - p) / (p * (1 - q));
			if (fabs(t - 1) < 1e-13) {
				printf("%.2lf\n", 1.0 * n / (m + n));
			} else {
				printf("%.2lf\n", (1 - pow(t, n))/(1 - pow(t, m + n)));
			}
		}
	}
	return 0;
}
