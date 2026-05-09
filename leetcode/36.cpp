class Solution {
public:
    int helper(int i, int j) {
        if (i < 3) {
            if (j < 3) return 0;
            if (j < 6) return 1;
            if (j < 9) return 2;
        } else if (i < 6) {
            if (j < 3) return 3;
            if (j < 6) return 4;
            if (j < 9) return 5;
        } else if (j < 9) {
            if (j < 3) return 6;
            if (j < 6) return 7;
            if (j < 9) return 8;
        }
        return 0;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> v(27);
        for (int i = 0; i < 27; ++i) {
            v[i].resize(9);
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num != '.') {
                    int realnum = num - 48;
                    if (v[i][realnum - 1] != 0) return false;
                    v[i][realnum - 1] = 1;
                    if (v[9 + j][realnum - 1] != 0) return false;
                    v[9 + j][realnum - 1] = 1;
                    if (v[18 + helper(i, j)][realnum - 1] != 0) return false;
                    v[18 + helper(i, j)][realnum - 1] = 1;
                }
            }
        }
        return true;
    }
};
