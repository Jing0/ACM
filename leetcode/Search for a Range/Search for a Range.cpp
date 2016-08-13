class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int lo = 0, hi = size - 1, mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (nums.at(mid) > target) {
                hi = mid - 1;
            } else if (nums.at(mid) < target) {
                lo = mid + 1;
            } else {
                break;
            }
        }
        vector<int> ans;
        int p;
        if (lo > hi) {
            if (lo >= size || nums.at(lo) != target) {
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
            p = lo;
        } else {
            p = mid; 
        }
        while (p >= 0 && nums.at(p) == target) {
            --p;
        }
        ++p;
        ans.push_back(p);
        while (p < size && nums.at(p) == target) {
            ++p;
        }
        --p;
        ans.push_back(p);
        return ans;
    }
};
