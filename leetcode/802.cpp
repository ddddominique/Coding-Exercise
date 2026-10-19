class Solution {
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int node) {
        if (visited[node] == 2) return false;
        if (visited[node] == 1) return true;
        visited[node] = 2;
        for (int neighbor : graph[node]) {
            if (!dfs(graph, visited, neighbor)) {
                return false;
            }
        }
        visited[node] = 1;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (dfs(graph, visited, i)) {
                result.push_back(i);
            }
        }
        return result;
    }
};