class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        for (int i = 0; i <= rowIndex; ++i) {
            row.push_back(1);
            for (int j = i - 1; j > 0; --j) {
                if (j > 0) {
                    row.at(j) += row.at(j - 1);
                }
            }
        }
        return row;
    }
};
