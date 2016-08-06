class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return 0;
        }
        int i;
        for (i = 1; i < size; ++i) {
            if (nums.at(i) < nums.at(i - 1)) {
                return i - 1;
            }
        }
        return size - 1;
    }
};
