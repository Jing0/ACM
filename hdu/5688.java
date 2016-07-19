/*
 * =====================================================================================
 *
 *       Filename:  5688.java
 *
 *    Description:  
 *    度熊所居住的 D 国，是一个完全尊重人权的国度。以至于这个国家的所有人命名自己的名字都非常奇怪。一个人的名字由若干个字符组成，同样的，这些字符的全排列的结果中的每一个字符串，也都是这个人的名字。例如，如果一个人名字是 ACM，那么 AMC， CAM， MAC， MCA， 等也都是这个人的名字。在这个国家中，没有两个名字相同的人。
 *    度熊想统计这个国家的人口数量，请帮助度熊设计一个程序，用来统计每一个人在之前被统计过多少次。
 *    Input
 *    这里包括一组测试数据，第一行包含一个正整数N，接下来的N 行代表了 N 个名字。N 不会超过100,000，他们的名字不会超过40位.
 *    Output
 *    对于每输入的一个人名，输出一个整数，代表这个人之前被统计了多少次。
 *    Sample Input
 *    5
 *    ACM
 *    MAC
 *    BBA
 *    ACM
 *    BAB
 *    Sample Output
 *    0
 *    1
 *    0
 *    2
 *    1
 *
 *        Created:  07/19/2016 16:50:36
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

import java.util.HashMap;
import java.util.Scanner;
import java.util.Arrays;
public class Main {
	public static void main(String args[]) {
		HashMap<String, Integer> name = new HashMap<String, Integer>();
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		for (int i = 0; i < n; ++i) {
			char[] charArray = scanner.next().toLowerCase().toCharArray();
			Arrays.sort(charArray);
			String tmpName = new String(charArray);
			int tmpCount;
			if (name.containsKey(tmpName)) {
				tmpCount = name.get(tmpName) + 1;
			} else {
				tmpCount = 0;
			}
			name.put(tmpName, tmpCount);
			System.out.println(tmpCount);
		}
	}
}

