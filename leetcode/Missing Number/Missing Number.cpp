class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        long sum = 0;
        int max = 0;
        for (int i = 0; i < size; ++i) {
            int num = nums.at(i);
            sum += num;
            max = num > max ? num : max;
        }
        long expected = (long)max * (max + 1) / 2;
        if (max + 1 == size && sum == expected) {
            return size;
        }
        return expected - sum;
    }
};
