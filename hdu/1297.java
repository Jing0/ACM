/*
 * =====================================================================================
 *
 *       Filename:  1297.java
 *
 *    Description:
 *    There are many students in PHT School. One day, the headmaster whose name is PigHeader wanted all students stand in a line. He prescribed that girl can not be in single. In other words, either no girl in the queue or more than one girl stands side by side. The case n=4 (n is the number of children) is like
 *    FFFF, FFFM, MFFF, FFMM, MFFM, MMFF, MMMM
 *    Here F stands for a girl and M stands for a boy. The total number of queue satisfied the headmaster’s needs is 7. Can you make a program to find the total number of queue with n children?
 *    Input
 *    There are multiple cases in this problem and ended by the EOF. In each case, there is only one integer n means the number of children (1<=n<=1000)
 *    Output
 *    For each test case, there is only one integer means the number of queue satisfied the headmaster’s needs.
 *    Sample Input
 *    1
 *    2
 *    3
 *    Sample Output
 *    1
 *    2
 *    4
 *
 *        Created:  08/07/2015 09:22:57
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

import java.util.*;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a;
        BigInteger[] b = new BigInteger[1010];
        b[1] = BigInteger.ONE;
        b[2] = BigInteger.valueOf(2);
        b[3] = BigInteger.valueOf(4);
        b[4] = BigInteger.valueOf(7);
        while (in.hasNext()) {
            a = in.nextInt();
            if (a < 5) {
                System.out.println(b[a]);
			}
            else {
                for (int i = 5; i <= a; i++) {
                    b[i] = b[i-1].add(b[i-2]).add(b[i-4]);
                }
                System.out.println(b[a]);
            }
        }
    }
}

