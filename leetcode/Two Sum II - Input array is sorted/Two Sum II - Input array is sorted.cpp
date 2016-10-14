class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int size = numbers.size();
        for (int i = 0; i < size; ++i) {
            int j = binSearch(numbers, i + 1, target - numbers.at(i));
            if (j != -1) {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            }
        }
        return ans;
    }
private:
    int binSearch(vector<int>& numbers, int begin, int target) {
        int lo = begin;
        int hi = numbers.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (target > numbers.at(mid)) {
                lo = mid + 1;
            } else if (target < numbers.at(mid)) {
                hi = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
