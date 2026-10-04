class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int result = 0;
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> myq;
        maze[entrance[0]][entrance[1]] = '+';
        myq.push({entrance[0], entrance[1]});
        vector<pair<int, int>> alldirs = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        };
        while(!myq.empty()) {
            int count = myq.size();
            for (int i = 0; i < count; ++i) {
                pair<int, int> currloc = myq.front();
                myq.pop();
                if ((currloc.first == 0 || currloc.first == m - 1 || currloc.second == 0 || currloc.second == n - 1) && result != 0) {
                    return result;
                }
                for (pair<int, int> dir : alldirs) {
                    int newi = dir.first + currloc.first;
                    int newj = dir.second + currloc.second;
                    if (newi >= 0 && newi < m && newj >= 0 && newj < n && maze[newi][newj] != '+') {
                        myq.push({newi, newj});
                        maze[newi][newj] = '+';
                    }
                }
            }
            result++;
        }
        return -1;
    }
};