public class Solution {
    public boolean isPowerOfFour(int num) {
        return num > 0 && Integer.toBinaryString(num).matches("1(00)*");
    }
}
