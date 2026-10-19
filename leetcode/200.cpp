class Solution {
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0') {
            return;
        }
        grid[x][y] = '0';
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    result += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        vector<pair<int, int>> alldirs = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    // found one
                    result++;
                    queue<pair<int, int>> myq;
                    myq.push({i, j});
                    while (!myq.empty()) {
                        pair<int, int> currloc = myq.front();
                        myq.pop();
                        for (pair<int, int>& dir : alldirs) {
                            int newi = currloc.first + dir.first;
                            int newj = currloc.second + dir.second;
                            if (newi >= 0 && newi < m && newj >= 0 && newj < n && grid[newi][newj] == '1') {
                                myq.push({newi, newj});
                                grid[newi][newj] = '0';
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};