class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int rownum = grid.size();
        int colnum = grid[0].size();
        int numlayers = min(rownum, colnum) / 2;
        for (int layer = 0; layer < numlayers; layer++) {
            int top = layer;
            int right = colnum - layer - 1;
            int bottom = rownum - layer - 1;
            int left = layer;
            vector<int> nums;
            // top
            for (int i = 0; i <= right - left; ++i) {
                nums.push_back(grid[top][i + layer]);
            }

            // right
            for (int i = 1; i <= bottom - top; ++i) {
                nums.push_back(grid[i + layer][right]);
            }
            // bottom'
            for (int i = right - left - 1; i >= 0; --i) {
                nums.push_back(grid[bottom][i + layer]);
            }

            // left
            for (int i = bottom - top - 1; i > 0; --i) {
                nums.push_back(grid[i + layer][left]);
            }

            int rotate = k % nums.size();
            vector<int> rotated(nums.size());
            for (int i = 0; i < nums.size(); ++i) {
                rotated[i] = nums[(i + rotate) % nums.size()];
            }
            // top
            int counter = 0;
            for (int i = 0; i <= right - left; ++i) {
                grid[top][i + layer] = rotated[counter++];
            }
            for (int i = 1; i <= bottom - top; ++i) {
                grid[i + layer][right] = rotated[counter++];
            }
            for (int i = right - left - 1; i >= 0; --i) {
                grid[bottom][i + layer] = rotated[counter++];
            }
            for (int i = bottom - top - 1; i > 0 ; --i) {
                grid[i + layer][left] = rotated[counter++];
            }
        }
        return grid;
    
    }
};
