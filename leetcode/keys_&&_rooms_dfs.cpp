class Solution {
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int index) {
        visited[index] = true;
        for (int key : rooms[index]) {
            if (!visited[key]) {
            dfs(rooms, visited, key);
            }

        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(rooms, visited, 0);
        int result = 0;
        for (bool hold : visited) {
            if (hold) result++;
        }
        return result == n;
    }
};