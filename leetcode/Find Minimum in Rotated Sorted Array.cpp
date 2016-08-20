class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums.at(0);
        }
        int lo = 0, hi = size - 1;
        if (nums.at(lo) < nums.at(hi)) {
            return nums.at(lo);
        }
        int min = nums.at(0);
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums.at(lo) <= nums.at(mid)) {
                if (min > nums.at(lo)) {
                    min = nums.at(lo);
                }
                lo = mid + 1;
            } else if (nums.at(lo) > nums.at(mid)) {
                if (min > nums.at(mid)) {
                    min = nums.at(mid);
                }
                hi = mid - 1;
            }
        }
        return min;
    }
};
