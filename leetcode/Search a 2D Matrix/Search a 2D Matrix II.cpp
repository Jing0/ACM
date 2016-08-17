class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size();
        int begin = -1, end;
        int i;
        for (i = 0; i < size; ++i) {
            int front = matrix.at(i).front();
            int back = matrix.at(i).back();
            if (begin == -1 && front <= target && target <= back) {
                begin = i;
            } else if (front > target) {
                break;
            }
        }
        end = i - 1;
        if (end < 0 || begin < 0) {
            return false;
        }
        for (int j = begin; j <= end; ++j) {
            if (binarySearch(matrix.at(j), target)) {
                return true;
            }
        }
        return false;
    }
private:
    bool binarySearch(vector<int> vec, int target) {
        int lo = 0;
        int hi = vec.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int num = vec.at(mid);
            if (num < target) {
                lo = mid + 1;
            } else if (num > target) {
                hi = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
