class Solution {
    int dfs(vector<vector<int>>& forward, vector<vector<int>>& back, vector<bool>& visited, int index) {
        visited[index] = true;
        int result = 0;
        for (int i : forward[index]) {
            if (!visited[i]) {
                result++;
                result += dfs(forward, back, visited, i);
            }
        }
        for (int i : back[index]) {
            if (!visited[i]) {
                result += dfs(forward, back, visited, i);
            }
        }
        return result;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forward(n); // a -> b
        vector<vector<int>> back(n); // b -> a
        for (auto& pair : connections) {
            forward[pair[0]].push_back(pair[1]);
            back[pair[1]].push_back(pair[0]);
        }

        vector<bool> visited(n, false);
        return dfs(forward, back, visited, 0);
    }
};