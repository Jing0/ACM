class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = board.size();
        for (int i = 0; i < size; ++i) {
            int a[9] = {0};
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int n = board[i][j] - '0' - 1;
                if (a[n]) {
                    return false;
                } else {
                    a[n]++;
                }
            }
        }
        for (int j = 0; j < size; ++j) {
            int a[9] = {0};
            for (int i = 0; i < size; ++i) {
                if (board[i][j] == '.') {
                    continue;
                }
                int n = board[i][j] - '0' - 1;
                if (a[n]) {
                    return false;
                } else {
                    a[n]++;
                }
            }
        }
        for (int i = 0; i < size; i += 3) {
            for (int j = 0; j < size; j += 3) {
                int a[9] = {0};
                for (int p = 0; p < 3; ++p) {
                    for (int q = 0; q < 3; ++q) {
                        if (board[i + p][j + q] == '.') {
                            continue;
                        }
                        int n = board[i + p][j + q] - '0' - 1;
                        if (a[n]) {
                            return false;
                        } else {
                            a[n]++;
                        }
                    }
                }
            }
        }
        return true;
    }
};
