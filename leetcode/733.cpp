class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc, int starting, int color) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() ||
        image[sr][sc] != starting) {
            return;
        }
        image[sr][sc] = color;
        dfs(image, sr + 1, sc, starting, color);
        dfs(image, sr - 1, sc, starting, color);
        dfs(image, sr, sc + 1, starting, color);
        dfs(image, sr, sc - 1, starting, color);
   
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int starting = image[sr][sc];
        if (starting == color) return image;
        image[sr][sc] = color;
        dfs(image, sr + 1, sc, starting, color);
        dfs(image, sr - 1, sc, starting, color);
        dfs(image, sr, sc + 1, starting, color);
        dfs(image, sr, sc - 1, starting, color);
        return image;
    }
};