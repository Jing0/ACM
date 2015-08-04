/*
 * =====================================================================================
 *
 *       Filename:  1170.c
 *
 *    Description:  It's easy to tell if two words are identical - just check the letters. But how do you tell if two words are almost identical? And how close is "almost"?
 * There are lots of techniques for approximate word matching. One is to determine the best substring match, which is the number of common letters when the words are compared letter-byletter.
 * The key to this approach is that the words can overlap in any way. For example, consider the words CAPILLARY and MARSUPIAL. One way to compare them is to overlay them:
 * CAPILLARY
 * MARSUPIAL
 * There is only one common letter (A). Better is the following overlay:
 * CAPILLARY
 *      MARSUPIAL
 * with two common letters (A and R), but the best is:
 *    CAPILLARY
 * MARSUPIAL
 * Which has three common letters (P, I and L).
 * The approximation measure appx(word1, word2) for two words is given by:
 * common letters * 2
 * -----------------------------
 *  length(word1) + length(word2)
 *  Thus, for this example, appx(CAPILLARY, MARSUPIAL) = 6 / (9 + 9) = 1/3. Obviously, for any word W appx(W, W) = 1, which is a nice property, while words with no common letters have an appx value of 0.
 *  Input:
 *  The input for your program will be a series of words, two per line, until the end-of-file flag of -1.
 *  Using the above technique, you are to calculate appx() for the pair of words on the line and print the result. For example:
 *  CAR CART
 *  TURKEY CHICKEN
 *  MONEY POVERTY
 *  ROUGH PESKY
 *  A A
 *  -1
 *  The words will all be uppercase.
 *  Output:
 *  Print the value for appx() for each pair as a reduced fraction, like this:
 *  appx(CAR,CART) = 6/7
 *  appx(TURKEY,CHICKEN) = 4/13
 *  appx(MONEY,POVERTY) = 1/3
 *  appx(ROUGH,PESKY) = 0
 *  appx(A,A) = 1
 *
 *        Created:  08/04/2015 16:57:58
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int strCheck (const char *str1, const char *str2, int len1, int len2) {
    int i, j, len, count, max = 0;
    for (i = 0; i < len2; ++i) {
        count = 0;
        len = MIN((len2 - i), len1);
        for (j = 0; j < len; ++j) {
            if (str1[j] == str2[i + j]) {
                ++count;
            }
        }
        if (max < count) {
            max = count;
        }
    }
    return max * 2;
}

int main(int argc, char const *argv[]) {
    char str1[MAXLEN], str2[MAXLEN];
    int count1, count2, count, len1, len2, divisor;
    while (scanf("%s", str1) != EOF) {
        if (strcmp(str1, "-1") == 0) {
            break;
        } else {
            scanf("%s", str2);
        }
        len1 = strlen(str1);
        len2 = strlen(str2);
        count1 = strCheck(str2, str1, len2, len1);
        count2 = strCheck(str1, str2, len1, len2);
        count = MAX(count1, count2);
        divisor = gcd(count, len1 + len2);
        printf("appx(%s,%s) = ", str1, str2);
        if (strcmp(str1, str2) == 0) {
            printf("1\n");
        } else if (count) {
            printf("%d/%d\n", count/divisor, (len1 + len2)/divisor);
        } else {
            printf("0\n");
        }
    }
    return 0;
}
