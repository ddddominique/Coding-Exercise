class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);

        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                result++;
                dfs(isConnected, visited, i);
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int index) {
        visited[index] = 1;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i] && isConnected[index][i]) {
                dfs(isConnected, visited, i);
            }
        }
    }
};