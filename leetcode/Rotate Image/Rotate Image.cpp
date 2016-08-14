class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                int t1 = matrix[i][j];
                int t2 = matrix[j][n - 1 - i];
                int t3 = matrix[n - 1 - i][n - 1 - j];
                int t4 = matrix[n - 1 - j][i];
                matrix[i][j] = t4;
                matrix[j][n - 1 - i] = t1;
                matrix[n - 1 - i][n - 1 - j] = t2;
                matrix[n - 1 - j][i] = t3;
            }
        }
    }
};
