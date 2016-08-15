class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (!size) {
            return ans;
        }
        int min = nums.front(), max = nums.back();
        for (int i = 0; i < size; ++i) {
            int a = nums.at(i);
            if (i && a == nums.at(i - 1)) {
                continue;
            }
            for (int j = i + 1; j < size - 1; ++j) {
                int b = nums.at(j);
                if (j > i + 1 && b == nums.at(j - 1)) {
                    continue;
                }
                if ((a + b < -max) || (a + b > -min)) {
                    continue;
                }
                if (binarySearch(nums, j + 1, size - 1, -a-b)) {
                    vector<int> t{a, b, -a-b};
                    if (!s.count(t)) {
                        s.insert(t);
                        ans.push_back(t);
                    }
                }
            }
        }
        return ans;
    }
private:
    bool binarySearch(vector<int> nums, int begin, int end, int target) {
        int lo = begin, hi = end;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int num = nums.at(mid);
            if (target > num) {
                lo = mid + 1;
            } else if (target < num) {
                hi = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
