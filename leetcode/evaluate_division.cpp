class Solution {
    double dfs(string curr, string target, unordered_map<string, unordered_map<string, double>>& adj,
    unordered_set<string>& visited) {
        if (!adj.count(curr) || !adj.count(target)) return -1.0;
        if (curr == target) return 1.0;

        visited.insert(curr);
        double result;
        for (auto& pair : adj[curr]) {
            string next = pair.first;
            double val = pair.second;
            if (!visited.count(next)) {
                result = dfs(next, target, adj, visited);
                if (result != -1.0) {return result * val;}
            }
        }
        return -1.0;


    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> result;

        unordered_map<string, unordered_map<string, double>> adj;

        for (int i = 0; i < equations.size(); ++i) {
            adj[equations[i][0]][equations[i][1]] = values[i];
            adj[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }

        for (int i = 0; i < queries.size(); ++i) {
            unordered_set<string> visited;
            result.push_back(dfs(queries[i][0], queries[i][1], adj, visited));
        }
        return result;
    }
};