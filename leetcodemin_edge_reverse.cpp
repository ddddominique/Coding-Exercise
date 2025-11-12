class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        vector<vector<int>> forward(n), back(n);
        for (auto pair: connections) {
            forward[pair[0]].push_back(pair[1]);
            back[pair[1]].push_back(pair[0]);
        }
        int result = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int road = q.front();
            visited[road] = true;
            q.pop();
            for (int f : forward[road]) {
                if (!visited[f]) {
                    result += 1;
                    q.push(f);
                }
            }

            for (int b : back[road]) {
                if (!visited[b]) {
                    q.push(b);
                }
            }
        }
        return result;
    }
};
