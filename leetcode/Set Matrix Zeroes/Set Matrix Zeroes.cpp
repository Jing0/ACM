class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false, firstCol = false;
        int rownum = matrix.size();
        int colnum = matrix[0].size();
        for (int i = 0; i < rownum; ++i) {
            for (int j = 0; j < colnum; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0 || j == 0) {
                        if (i == 0) {
                            firstRow = true;
                        }
                        if (j == 0) {
                            firstCol = true;
                        }
                    } else {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        for (int i = 1; i < rownum; ++i) {
            if (matrix[i][0] == 0) {
                setRowZero(matrix, colnum, i);
            }
        }
        for (int i = 1; i < colnum; ++i) {
            if (matrix[0][i] == 0) {
                setColZero(matrix, rownum, i);
            }
        }
        if (firstRow) {
            setRowZero(matrix, colnum, 0);
        }
        if (firstCol) {
            setColZero(matrix, rownum, 0);
        }
        if (firstRow || firstCol) {
            matrix[0][0] = 0;
        }
    }
private:
    void setRowZero(vector<vector<int>>& matrix, int colnum, int row) {
        for (int i = 0; i < colnum; ++i) {
            matrix[row][i] = 0;
        }
    }
    void setColZero(vector<vector<int>>& matrix, int rownum, int col) {
        for (int i = 0; i < rownum; ++i) {
            matrix[i][col] = 0;
        }
    }
};