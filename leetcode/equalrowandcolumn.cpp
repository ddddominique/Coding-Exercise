class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> other;
        for (int i = 0; i < n; ++i) {
            vector<int> hold;
            for (int j = 0; j < n; ++j) {
                hold.push_back(grid[j][i]);
            }
            other.push_back(hold);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                            if (other[i] == grid[j]) {result ++;}
            }

        }
        return result;
    }
};