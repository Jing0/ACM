/*
 * =====================================================================================
 *
 *       Filename:  5686.java
 *
 *    Description:  
 *    度熊面前有一个全是由1构成的字符串，被称为全1序列。你可以合并任意相邻的两个1，从而形成一个新的序列。对于给定的一个全1序列，请计算根据以上方法，可以构成多少种不同的序列。
 *    Input
 *    这里包括多组测试数据，每组测试数据包含一个正整数N，代表全1序列的长度。
 *    1≤N≤200
 *    Output
 *    对于每组测试数据，输出一个整数，代表由题目中所给定的全1序列所能形成的新序列的数量。
 *    Sample Input
 *    1
 *    3
 *    5
 *    Sample Output
 *    1
 *    3
 *    8
 *
 * Hint
 * 如果序列是：(111)。可以构造出如下三个新序列：(111), (21), (12)。
 *
 *        Created:  07/19/2016 21:43:11
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

import java.util.Scanner;
import java.math.BigInteger;
public class Main {
	public static void main(String args[]) {
		BigInteger[] m = new BigInteger[201];
		m[0] = BigInteger.valueOf(0);
		m[1] = BigInteger.valueOf(1);
		m[2] = BigInteger.valueOf(2);
		for (int i = 3;i < 201; ++i) {
			m[i] = m[i-1].add(m[i-2]);
		}
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNext()) {
			int n = scanner.nextInt();
			System.out.println(m[n]);
		}
	}
}

