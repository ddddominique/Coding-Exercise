class Solution {
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < isConnected[i].size(); ++j) {
            if (visited[j] == 0 && isConnected[i][j]) {
                dfs(isConnected, visited, j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n , false);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                result++;
                dfs(isConnected, visited, i);
            }
        }
        return result;
    }
};