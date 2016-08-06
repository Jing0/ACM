/*
 * =====================================================================================
 *
 *       Filename:  1207.c
 *
 *    Description:  
 *    经典的汉诺塔问题经常作为一个递归的经典例题存在。可能有人并不知道汉诺塔问题的典故。汉诺塔来源于印度传说的一个故事，上帝创造世界时作了三根金刚石柱子，在一根柱子上从下往上按大小顺序摞着64片黄金圆盘。上帝命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一回只能移动一个圆盘。有预言说，这件事完成时宇宙会在一瞬间闪电式毁灭。也有人相信婆罗门至今仍在一刻不停地搬动着圆盘。恩，当然这个传说并不可信，如今汉诺塔更多的是作为一个玩具存在。Gardon就收到了一个汉诺塔玩具作为生日礼物。
 *    Gardon是个怕麻烦的人（恩，就是爱偷懒的人），很显然将64个圆盘逐一搬动直到所有的盘子都到达第三个柱子上很困难，所以Gardon决定作个小弊，他又找来了一根一模一样的柱子，通过这个柱子来更快的把所有的盘子移到第三个柱子上。下面的问题就是：当Gardon在一次游戏中使用了N个盘子时，他需要多少次移动才能把他们都移到第三个柱子上？很显然，在没有第四个柱子时，问题的解是2^N-1，但现在有了这个柱子的帮助，又该是多少呢？
 *    Input
 *    包含多组数据，每个数据一行，是盘子的数目N(1<=N<=64)。
 *    Output
 *    对于每组数据，输出一个数，到达目标需要的最少的移动数。
 *    Sample Input
 *    1
 *    3
 *    12
 *    Sample Output
 *    1
 *    5
 *    81
 *
 *        Created:  08/06/2015 17:04:18
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(void) {
	int n, a[65] = {0, 1}, i, j, k = 1;
	for (i = 2; i < 65; ++k) {
		for (j = 0; j < k + 1; ++j, ++i) { 
			a[i] = a[i - 1] + (1<<k);
		}
	}
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", a[n]);
	}
	return 0;
}