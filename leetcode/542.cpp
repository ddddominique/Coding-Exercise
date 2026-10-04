class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int length = 0;
        vector<vector<int>> result(m, vector<int>(n, 0));
        queue<pair<int, int>> myq;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    myq.push({i, j});
                }
            }
        }
        vector<pair<int, int>> alldir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!myq.empty()) {
            length++;
            int count = myq.size();
            for (int i = 0; i < count; ++i) {
                pair<int, int> currloc = myq.front();
                myq.pop();
                for (pair<int, int> dir : alldir) {
                    int newi = currloc.first + dir.first;
                    int newj = currloc.second + dir.second;
                    if (newi >= 0 && newi < m && newj >= 0 && newj < n && mat[newi][newj] == 1) {
                        result[newi][newj] = length;
                        mat[newi][newj] = 0;
                        myq.push({newi, newj});
                    }
                }
            }
        }
        return result;
    }
};