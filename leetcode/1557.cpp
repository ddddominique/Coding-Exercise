class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n);
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            indeg[v]++;
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) result.push_back(i);
        }
        return result;
    }
};