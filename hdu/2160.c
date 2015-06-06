/*
 * =====================================================================================
 *
 *       Filename:  2160.c
 *
 *    Description:  
 *    话说现在猪肉价格这么贵，著名的ACBoy 0068 也开始了养猪生活。说来也奇怪，他养的猪一出生第二天开始就能每天中午生一只小猪，而且生下来的竟然都是母猪。
 *    不过光生小猪也不行，0068采用了一个很奇特的办法来管理他的养猪场：
 *    对于每头刚出生的小猪，在他生下第二头小猪后立马被杀掉，卖到超市里。
 *    假设在创业的第一天，0068只买了一头刚出生的小猪，请问，在第N天晚上，0068的养猪场里还存有多少头猪？
 *    Input
 *    测试数据的第一行包含有一个正整数T，代表测试数据的个数。接下来有T组测试，每组测试数据占一行，分别有一个正整数N代表0068创业的第N天。(0<N<20)
 *    Output
 *    对于每组数据，请在一行里输出第N天晚上养猪场里猪的数目。
 *    Sample Input
 *    2
 *    2
 *    3
 *    Sample Output
 *    2
 *    3
 *
 *        Created:  06/06/2015 15:36:55
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
	int t,i,n,a[22]={0,1,2,3};
	for(i=4;i<22;++i){
		a[i]=a[i-1]+a[i-2];
	}
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}
