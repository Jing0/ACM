/*
 * =====================================================================================
 *
 *       Filename:  1181.c
 *
 *    Description:  
 *    呃......变形课上Harry碰到了一点小麻烦,因为他并不像Hermione那样能够记住所有的咒语而随意的将一个棒球变成刺猬什么的,但是他发现了变形咒语的一个统一规律:如果咒语是以a开头b结尾的一个单词,那么它的作用就恰好是使A物体变成B物体. 
 *    Harry已经将他所会的所有咒语都列成了一个表,他想让你帮忙计算一下他是否能完成老师的作业,将一个B(ball)变成一个M(Mouse),你知道,如果他自己不能完成的话,他就只好向Hermione请教,并且被迫听一大堆好好学习的道理.
 *    Input
 *    测试数据有多组。每组有多行，每行一个单词,仅包括小写字母,是Harry所会的所有咒语.数字0表示一组输入结束.
 *    Output
 *    如果Harry可以完成他的作业,就输出"Yes.",否则就输出"No."(不要忽略了句号)
 *    Sample Input
 *    so
 *    soon
 *    river
 *    goes
 *    them
 *    got
 *    moon
 *    begin
 *    big
 *    0
 *    Sample Output
 *    Yes.
 *
 *        Created:  08/11/2015 11:11:33
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#define MAX_N 27
char map[MAX_N - 1][MAX_N];
int search(int n) {
	if (map[n]['m' - 'a' + 1] == 1) {
		return 1;
	}
	int i;
	for (i = 1; i < MAX_N; ++i) {
		if (map[n][i] == 1 && map[i - 1][0]) {
			map[i - 1][0] = 0;
			if (search(i - 1) == 1) {
				return 1;
			}
		}
	}
	return 0;
}
int main(void) {
	int len, hasM, hasB;
	char str[100];
    while (1) {
		memset(map, 0, sizeof(map));
		hasM = hasB = 0;
		if (scanf("%s", str) == EOF) {
			break;
		}
        do {
			if (strcmp(str, "0") == 0) {
				break;
			}
			len = strlen(str);
			if (len == 1) {
				continue;
			}
			if (str[len - 1] == 'b') {
				continue;
			} else if (str[len - 1] == 'm') {
				hasM = 1;
			}
			if (str[0] == 'b') {
				hasB = 1;
			}
			map[str[0] - 'a'][str[len - 1] - 'a' + 1] = 1;
			map[str[0] - 'a'][0] = 1;
        } while (scanf("%s", str) != EOF);
		if (hasM && hasB) {
        	printf("%s.\n", search(1) ? "Yes" : "No");
		} else {
			puts("No.");
		}
    }
    return 0;
}
