class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int result = 0;
        map<vector<int>, int> count;
        for (auto row : grid) {
            count[row]++;
        }

        for (int i = 0; i < n ; ++i) {
            vector<int> myvec;
            for (int j = 0; j < n; ++j) {
                myvec.push_back(grid[j][i]);
            }
            result += count[myvec];
        }
        return result;
    }
};