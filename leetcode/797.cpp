class Solution {
    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result, int node) {
        if (node == graph.size() -1) {
            result.push_back(path);
            return;
        }
        for (int n : graph[node]) {
            path.push_back(n);
            dfs(graph, path, result, n);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        vector<vector<int>> result;
        int endnode = graph.size() - 1;
        dfs(graph, path, result, 0);
        return result;
    }
};