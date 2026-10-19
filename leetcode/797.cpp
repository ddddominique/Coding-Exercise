class Solution {
    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result, int node) {
        if (node == graph.size() - 1) {
            result.push_back(path);
            return;
        }
        for (int neighbor : graph[node]) {
            path.push_back(neighbor);
            dfs(graph, path, result, neighbor);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> result;
        vector<int> path = {0};
        dfs(graph, path, result, 0);
        return result;
    }
};