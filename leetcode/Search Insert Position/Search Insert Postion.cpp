class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = -1;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (target == nums.at(i)) {
                ans = i;
                break;
            } else if (target < nums.at(i)) {
                if (i == 0) {
                    ans = 0;
                } else {
                    ans = i;
                }
                break;
            }
        }
        if (ans == -1) {
            ans = size;
        }
        return ans;
    }
};
