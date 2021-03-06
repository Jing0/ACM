/*
 * =====================================================================================
 *
 *       Filename:  1597.c
 *
 *    Description:  
 *    假设：
 *    S1 = 1
 *    S2 = 12
 *    S3 = 123
 *    S4 = 1234
 *    .........
 *    S9 = 123456789
 *    S10 = 1234567891
 *    S11 = 12345678912
 *    ............
 *    S18 = 123456789123456789
 *    ..................
 *    现在我们把所有的串连接起来
 *    S = 1121231234.......123456789123456789112345678912.........
 *    那么你能告诉我在S串中的第N个数字是多少吗？
 *
 *    Input
 *    输入首先是一个数字K，代表有K次询问。
 *    接下来的K行每行有一个整数N(1 <= N < 2^31)。
 *    Output
 *    对于每个N，输出S中第N个对应的数字.
 *    Sample Input
 *    6
 *    1
 *    2
 *    3
 *    4
 *    5
 *    10
 *    Sample Output
 *    1
 *    1
 *    2
 *    1
 *    2
 *    4
 *
 *        Created:  02/15/2015 14:59:08
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
int main(){
	int i,k,m,n;
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		for(i=1,m=n;i<n+1;++i){
			if(m-i<=0){
				printf("%d\n",m%9?m%9:9);
				break;
			}
			m-=i;
		}
	}
	return 0;
}
