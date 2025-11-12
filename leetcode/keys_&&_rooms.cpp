class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;

        visited[0] = true;
        q.push(0);

        int seen = 1;

        while(!q.empty()) {
            int room = q.front();
            q.pop();

            for (int key:rooms[room]) {
                if (!visited[key]) {
                    seen++;
                    visited[key] = true;
                    q.push(key);
                }
            }
        }
        return seen == n;
    }
};