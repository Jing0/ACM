class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int> ve;
        for (int i = 0; i < row; ++i) {
            vector<int> vrow = triangle.at(i);
            if (i == 0) {
                ve.push_back(vrow.at(0));
            } else {
                for (int j = i; j > 0; --j) {
                    if (j == i) {
                        ve.push_back(vrow.at(j) + ve.at(j - 1));
                    } else {
                        ve.at(j) = min(ve.at(j), ve.at(j - 1)) + vrow.at(j);
                    }
                }
                ve.at(0) += vrow.at(0);
            }
        }
        int min = ve.at(0);
        for (int i = 0; i < row; ++i) {
            if (ve.at(i) < min) {
                min = ve.at(i);
            }
        }
        return min;
    }
};
