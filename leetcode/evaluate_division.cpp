class Solution {
    double dfs(string curr, string target, unordered_map<string, unordered_map<string, double>>& adj, unordered_set<string>& visited) {
        if (!adj.count(curr) || !adj.count(target)) return -1.0;
        if (curr == target) return 1.0;
        visited.insert(curr);
        double result;
        for (auto& pair : adj[curr]) {
            string next = pair.first;
            double weight = pair.second;
            if (!visited.count(next)) {
            double result = dfs(next, target, adj, visited);
            if (result != -1.0) {return result * weight;}
            }

        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        vector<double> result;
        unordered_map<string, unordered_map<string, double>> adj;

        for (int i = 0; i < n; ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            adj[u][v] = values[i];
            adj[v][u] = 1.0/values[i];
        }
        for (int i = 0; i < queries.size(); ++i) {
                    unordered_set<string> visited;
            result.push_back(dfs(queries[i][0], queries[i][1], adj, visited));
        }
        return result;
        
    }
};
