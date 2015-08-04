/*
 * =====================================================================================
 *
 *       Filename:  1178.c
 *
 *    Description:  
 *    Famous Harry Potter,who seemd to be a normal and poor boy,is actually a wizard.Everything changed when he had his birthday of ten years old.A huge man called 'Hagrid' found Harry and lead him to a new world full of magic power. 
 *    If you've read this story,you probably know that Harry's parents had left him a lot of gold coins.Hagrid lead Harry to Gringotts(the bank hold up by Goblins). And they stepped into the room which stored the fortune from his father.Harry was astonishing ,coz there were piles of gold coins. 
 *    The way of packing these coins by Goblins was really special.Only one coin was on the top,and three coins consisted an triangle were on the next lower layer.The third layer has six coins which were also consisted an triangle,and so on.On the ith layer there was an triangle have i coins each edge(totally i*(i+1)/2).The whole heap seemed just like a pyramid.Goblin still knew the total num of the layers,so it's up you to help Harry to figure out the sum of all the coins.
 *    Input
 *    The input will consist of some cases,each case takes a line with only one integer N(0<N<2^31).It ends with a single 0.
 *    Output
 *    对于每个输入的N,输出一行,采用科学记数法来计算金币的总数(保留三位有效数字)
 *    Sample Input
 *    1
 *    3
 *    0
 *    Sample Output
 *    1.00E0
 *    1.00E1
 *
 *        Created:  08/04/2015 17:00:39
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
int main(void) {
	int e;
	long i, n;
	double sum;
	while(scanf("%ld", &n) != EOF) {
		if (!n) {
			break;
		}
		sum = (1.0 * n * (n + 1) * (n + 2)) / 6.0;
		for (e = 0; sum >= 10.0; ++e) {
			sum /= 10.0;
		}
		printf("%.2lfE%d\n", sum, e);
	}
	return 0;
}
