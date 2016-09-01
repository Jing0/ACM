class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return true;
        }
        for (int i = 1; i < size; ++i) {
            if (nums.at(size - 1 - i) >= i) {
                if (i == size - 1) {
                    return true;
                }
                size -= i;
                i = 0;
            }
        }
        return false;
    }
};
