class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int result = 0;
        int rows = maze.size();
        int cols = maze[0].size();

        while (!q.empty()) {
            result++;
            int mysize = q.size();
            for (int i = 0; i < mysize; ++i) {
                auto curr = q.front();
                q.pop();

                vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (auto [r, c] : directions) {
                    int nr = r + curr.first;
                    int nc = c + curr.second;

                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                        continue;
                    }

                    if (maze[nr][nc] == '.') {
                        if (nr == 0 || nr == rows - 1 || nc == 0 || nc == cols - 1) {
                            return result;
                        }
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }

            }

        }

        return -1;
    }
};