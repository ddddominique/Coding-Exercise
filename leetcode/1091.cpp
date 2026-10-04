class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> myq;
        int result = 0;
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        myq.push({0, 0});
        grid[0][0] = 1;
        vector<pair<int, int>> alldirs = {
            {0, -1}, {0, 1}, {1, 0}, {-1, 0},
            {1, -1}, {-1, -1}, {-1, 1}, {1, 1}
        };
        while (!myq.empty()) {
            int count = myq.size();
            result++;
            for (int i = 0; i < count; ++i) {
                pair<int, int> myloc = myq.front();
                if (myloc.first == n - 1 && myloc.second == n - 1) return result;
                myq.pop();
                for (pair<int, int> loc : alldirs) {
                    int newi = loc.first + myloc.first;
                    int newj = loc.second + myloc.second;
                    if (newi >= 0 && newi < n && newj >= 0 && newj < n && grid[newi][newj] == 0) {
                        grid[newi][newj] = 1;
                        myq.push({newi, newj});
                    }
                }
            }
        }
        return -1;
    }
};
