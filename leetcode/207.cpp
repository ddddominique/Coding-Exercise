class Solution {
    bool dfs(vector<vector<int>>& adj, vector<int>& visited, int course) {
        if (visited[course] == 2) return true;
        if (visited[course] == 1) return false;
        visited[course] = 2; // 2 means in use
        for (int neighbor : adj[course]) {
            if (dfs(adj, visited, neighbor)) {
                return true;
            }
        }
        visited[course] = 1;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> visited(n, 0);
        vector<vector<int>> adj(n);
        for (vector<int> pre : prerequisites) {
            int a = pre[0];
            int b = pre[1];
            adj[a].push_back(b);
        }
        // 
        for (int i = 0; i < n; ++i) {
            if (dfs(adj, visited, i)) {
                return false;
            }
        }
        return true;
    }
};