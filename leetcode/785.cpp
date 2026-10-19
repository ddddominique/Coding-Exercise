class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; ++i) {
            if (color[i] !=  -1) continue;
            queue<int> myq;
            myq.push(i);
            color[i] = 0;
            while (!myq.empty()) {
                int curr = myq.front();
                myq.pop();
                for (int neighbor : graph[curr]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[curr];
                        myq.push(neighbor);
                    } else if (color[neighbor] == color[curr]){
                        return false;
                    }
                }
            }

        }
        return true;
        
    }
};