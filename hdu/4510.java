/*
 * =====================================================================================
 *
 *       Filename:  4510.java
 *
 *    Description:  
 *    Input
 *    输入首先包含一个整数N，表示有N组测试用例。
 *    接下来的N行表示N个测试用例，每行包括2个时间HH:MM:SS hh:mm:ss
 *    HH:MM:SS表示当前的时间，hh:mm:ss表示希望倒退回去的时间。
 *    [Technical Specification]
 *    00<=HH<=11
 *    00<=hh<=99
 *    00<=MM, SS, mm, ss<=59
 
 *    Output
 *    请计算并输出钟表倒退后显示的时间，要求输出格式为HH:MM:SS（即时分秒均显示2位，不足则补0），每组数据输出占一行。
 
 *    Sample Input
 *    2
 *    11:28:32 02:14:21
 *    05:00:00 96:00:01
 
 *    Sample Output
 *    09:14:11
 *    04:59:59
 *
 *        Created:  12/07/2015 16:20:38
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */
 import java.util.Scanner;
 public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int q = sc.nextInt();
            for (int w = 0; w < q; w++) {
                String x = sc.next();
                String y = sc.next();
                int x1 = (x.charAt(0) - 48) * 10 + (x.charAt(1) - 48);
                int y1 = (x.charAt(3) - 48) * 10 + (x.charAt(4) - 48);
                int z1 = (x.charAt(6) - 48) * 10 + (x.charAt(7) - 48);
                int x2 = (y.charAt(0) - 48) * 10 + (y.charAt(1) - 48);
                int y2 = (y.charAt(3) - 48) * 10 + (y.charAt(4) - 48);
                int z2 = (y.charAt(6) - 48) * 10 + (y.charAt(7) - 48);
                int x3 = x1 - x2 % 12;
                int y3 = y1 - y2;
                int z3 = z1 - z2;
                if (z3 < 0) {
                    y3--;
                    z3 = 60 + z3;
                }
                if (y3 < 0) {
                    x3--;
                    y3 = 60 + y3;
                }
                if (x3 < 0) {
                    x3 = 12 + x3;
                }
                System.out.printf("%02d:%02d:%02d", x3, y3, z3);
                System.out.println();
            }
        }
    }
}
