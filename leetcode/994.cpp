class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int result = 0;
        queue<pair<int, int>> myq;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    myq.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!myq.empty()) {
            if (fresh == 0) {return result;}
            result++;
            int mysize = myq.size();
            for (int j = 0; j < mysize; ++j) {
                pair<int, int> hold = myq.front();
                myq.pop();
                for (int i = 0; i < 4; ++i) {
                pair<int, int> currdir = directions[i];
                int newi = hold.first + currdir.first;
                int newj = hold.second + currdir.second;
                if (newi < m && newi >= 0 && newj < n && newj >= 0 && grid[newi][newj] == 1) {
                    fresh--;
                    grid[newi][newj] = 2;
                    myq.push({newi, newj});
                }
            }
            }


        }
        if (fresh == 0) return result;
        return -1;
    }
};