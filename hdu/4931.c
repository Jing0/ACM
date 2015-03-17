/*
 * =====================================================================================
 *
 *       Filename:  4931.c
 *
 *    Description:  
 *    Dong-hao , Grandpa Shawn , Beautful-leg Mzry are good friends. One day , they want to play a game.
 *    There are 6 numbers on the table.
 *    Firstly , Dong-hao can change the order of 6 numbers.
 *    Secondly , Grandpa Shawn take the first one and the last one , sum them up as his scores.
 *    Thirdly , Beautiful-leg Mzry take any of 3 numbers from the last 4 numbers , and sum them up as his scores.
 *    Finally , if Grandpa Shawn's score is larger than Beautiful-leg Mzry's , Granpa Shawn wins!
 *    If Grandpa Shawn's score is smaller than Beautiful-leg Mzry's , Granpa Shawn loses.
 *    If the scores are equal , there is a tie.
 *    Nowadays , it's really sad that Grandpa Shawn loses his love. So Dong-hao wants him to win(not even tie). You have to tell Dong-hao whether he can achieve his goal.
 *    Input
 *    There is a number T shows there are T test cases below. ( T <= 50)
 *    For each test case , there are 6 numbers Ai ( 1 <= Ai <= 100 ).
 *    Output
 *    If Dong-hao can achieve his goal , output "Grandpa Shawn is the Winner!"
 *    If he can not , output "What a sad story!"
 *    Sample Input
 *    3
 *    1 2 3 3 2 2
 *    2 2 2 2 2 2
 *    1 2 2 2 3 4
 *    Sample Output
 *    What a sad story!
 *    What a sad story!
 *    Grandpa Shawn is the Winner!
 *
 *        Created:  03/17/2015 19:04:04
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return *(int *)b-*(int *)a;
}
int main(){
	int i,t,a[6],flag;
	scanf("%d",&t);
	while(t--){
		for(i=0;i<6;++i)
			scanf("%d",&a[i]);
		qsort(a,6,sizeof(int),cmp);
		flag=(a[0]+a[1])>(a[2]+a[3]+a[4]);
		printf("%s\n",flag?"Grandpa Shawn is the Winner!":"What a sad story!");
	}
	return 0;
}
