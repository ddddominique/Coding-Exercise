class Solution {
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int i) {
        visited[i] = 1;
        for (int j = 0; j < isConnected.size(); ++j) {
            if (visited[j] == 0 && isConnected[i][j] == 1) {
                dfs(isConnected, visited, j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> visited(n, 0);
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