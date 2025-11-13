class Solution {
    double dfs(string curr, string target, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
        if (graph.find(curr) == graph.end() || graph.find(target) == graph.end()) return -1.0;
        if (curr == target) {return 1.0;}

        visited.insert(curr);
        for (auto& neighbor : graph[curr]) {
            string next = neighbor.first;
            double weight = neighbor.second;
            if (!visited.count(next)) {
                double result = dfs(next, target, graph, visited);
                if (result != -1.0) {return weight * result;}
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0], v = equations[i][1];
            double value = values[i];
            graph[u][v] = value;
            graph[v][u] = 1.0/value;
        }

        vector<double> result;
        for (auto& query : queries) {
            string start = query[0], end = query[1];
            unordered_set<string> visited;
            result.push_back(dfs(start, end, graph, visited));
        }
        return result;

        
    }
};