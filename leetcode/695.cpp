class Solution {
    void dfs(int& temp, vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        if (grid[i][j] == 1) {
            temp += 1;
            grid[i][j] = 0;
            dfs(temp, grid, i + 1, j);
            dfs(temp, grid, i - 1, j);
            dfs(temp, grid, i, j - 1);
            dfs(temp, grid, i, j + 1);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int temp = 0;
                    dfs(temp, grid, i, j);
                    result = max(result, temp);
                }
            }
        }
        return result;
    }
};