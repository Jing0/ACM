/*
 * 对数进行分组
 * diff 结果中两个数不同的最低位，此为分组依据
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ones = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            ones ^= nums.at(i);
        }
        int diff = 1;
        while ((ones & diff) == 0) {
            diff <<= 1;
        }
        int a = 0, b = 0;
        for (int i = 0; i < size; ++i) {
            int num = nums.at(i);
            if (num & diff) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        vector<int> ans{a, b};
        return ans;
    }
};
