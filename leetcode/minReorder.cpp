class Solution {
    int dfs(int i, vector<bool>& visited, vector<vector<int>>& forward, vector<vector<int>>& back) {
        visited[i] = true;
        int result = 0;
        for (int j : forward[i]) {
            if (visited[j] == false) {
                result++;
                result += dfs(j, visited, forward, back);
            }
        }
        for (int j : back[i]) {
            if (visited[j] == false) {
            result += dfs(j, visited, forward, back);
            }

        }
        return result;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forward(n);
        vector<vector<int>> back(n);

        for (int i = 0; i < connections.size(); ++i) {
            forward[connections[i][0]].push_back(connections[i][1]);
            back[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n, false);
        return dfs(0, visited, forward, back);
    }
};