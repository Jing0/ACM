public class Solution {
    public int removeDuplicates(int[] nums) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int dupCount = 0;
        for (int i = 0; i < nums.length; ++i) {
            Integer val = map.get(nums[i]);
            if (val == null) {
                map.put(nums[i], 1);
            } else {
                int count = val.intValue();
                if (count == 1) {
                    map.put(nums[i], 2);
                } else if (count == 2) {
                    dupCount++;
                }
            }
            if (dupCount != 0) {
                nums[i - dupCount] = nums[i];
            }
        }
        return nums.length - dupCount;
    }
}
