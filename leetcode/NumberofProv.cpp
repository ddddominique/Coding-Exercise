class Solution {
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i] = true;
        int n = isConnected.size();
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && isConnected[i][j]) {
                dfs(isConnected, visited, j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int result = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                result++;
                dfs(isConnected, visited, i);
            }
        }
        return result;
    }
};
