class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size();
        int i;
        for (i = 0; i < size; ++i) {
            if (matrix.at(i).at(0) > target) {
                break;
            }
        }
        --i;
        if (i < 0) {
            return false;
        }
        int lo = 0;
        int hi = matrix.at(i).size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int num = matrix.at(i).at(mid);
            if (num > target) {
                hi = mid - 1;
            } else if (num < target) {
                lo = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
