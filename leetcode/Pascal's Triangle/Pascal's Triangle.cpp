class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        for (int i = 0; i < numRows; ++i) {
            vector<int> row;
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    row.push_back(1);
                } else {
                    vector<int> lastrow = ans.at(i - 1);
                    row.push_back(lastrow.at(j - 1) + lastrow.at(j));
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};
