class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> myq;
        myq.push(source);
        vector<bool> visited(n, false);
        visited[source] = true;
        while (!myq.empty()) {
            int curr = myq.front();
            myq.pop();
            if (curr == destination) return true;
            for (int neighbor : adj[curr]) {
                if (visited[neighbor] == false) {
                    myq.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return false;
    }
};