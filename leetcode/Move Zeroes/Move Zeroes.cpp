class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums.at(i) == 0) {
                count++;
            } else {
                nums.at(i - count) = nums.at(i);
            }
        }
        for (int i = 0; i < count; ++i) {
            nums.at(size - 1 - i) = 0;
        }
    }
};
