public class Solution {
    public int majorityElement(int[] nums) {
        int ans = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; ++i) {
            int count;
            if (map.get(nums[i]) != null) {
                count = map.get(nums[i]);
                count++;
            } else {
                count = 1;
            }
            if (count > nums.length / 2) {
                ans = nums[i];
                break;
            }
            map.put(nums[i], count);
        }
        return ans;
    }
}
