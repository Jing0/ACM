/*
 * =====================================================================================
 *
 *       Filename:  1209.c
 *
 *    Description:  
 *    There is an analog clock with two hands: an hour hand and a minute hand. The two hands form an angle. The angle is measured as the smallest angle between the two hands. The angle between the two hands has a measure that is greater than or equal to 0 and less than or equal to 180 degrees.
 *    Given a sequence of five distinct times written in the format hh : mm , where hh are two digits representing full hours (00 <= hh <= 23) and mm are two digits representing minutes (00 <= mm <= 59) , you are to write a program that finds the median, that is, the third element of the sorted sequence of times in a nondecreasing order of their associated angles. Ties are broken in such a way that an earlier time precedes a later time.
 *    For example, suppose you are given a sequence (06:05, 07:10, 03:00, 21:00, 12:55) of times. Because the sorted sequence is (12:55, 03:00, 21:00, 06:05, 07:10), you are to report 21:00.
 *    Input
 *    The input consists of T test cases. The number of test cases (T) is given on the first line of the input file. Each test case is given on a single line, which contains a sequence of five distinct times, where times are given in the format hh : mm and are separated by a single space.
 *    Output
 *    Print exactly one line for each test case. The line is to contain the median in the format hh : mm of the times given. The following shows sample input and output for three test cases.
 *    Sample Input
 *    3
 *    00:00 01:00 02:00 03:00 04:00
 *    06:05 07:10 03:00 21:00 12:55
 *    11:05 12:05 13:05 14:05 15:05
 *    Sample Output
 *    02:00
 *    21:00
 *    14:05
 *
 *        Created:  08/07/2015 10:27:11
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
double ang[6];
int h[6], m[6], t, i, j;
int main() {
    scanf("%d", &t);
    while (t--) {
        memset(ang, 0, sizeof(ang));
        for (i = 0; i < 5; ++i) {
            scanf("%d:%d", &h[i], &m[i]);
            if (h[i] > 12) {
                ang[i] = fabs((h[i] - 12) * 30.0 - m[i] * 6.0 + m[i] * 1.0 / 2);
            } else {
                ang[i] = fabs(h[i] * 30.0 - m[i] * 6.0 + m[i] * 1.0 / 2);
            }
            if (ang[i] > 180) {
                ang[i] = 360 - ang[i];
            }
        }
        for (i = 0; i < 4; ++i) {
            for (j = i + 1; j < 5; ++j) {
                if (ang[i] > ang[j] || (ang[i] == ang[j] && h[i] > h[j]) || (h[i] == h[j] && m[i] > m[j] && ang[i] == ang[j])) {
                    int h1, m1;
                    double an;
                    an = ang[i];
                    ang[i] = ang[j];
                    ang[j] = an;
                    h1 = h[i];
                    m1 = m[i];
                    h[i] = h[j];
                    m[i] = m[j];
                    h[j] = h1;
                    m[j] = m1;
                }
            }
        }
        printf("%02d:%02d\n", h[2], m[2]);
    }
    return 0;
}
