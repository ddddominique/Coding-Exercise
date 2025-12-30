class Solution {

public:
struct Node {
    int r, c, t;
};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<Node> q;
        int fresh = 0;

        //1. add rotten oranges and count fresh
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int hold1[4] = {-1, 1, 0, 0};
        int hold2[4] = {0, 0, -1, 1};

        int result = 0, rotten = 0;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            result = max(result, curr.t);

            for (int k = 0; k < 4; ++k) {
                int nr = curr.r + hold1[k];
                int nc = curr.c + hold2[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc, curr.t + 1});
                    rotten++;
                }
            }
        }

        return rotten == fresh ? result : -1;        

        
    }
};