class Solution {
    void dfs(vector<vector<int>>& rooms, int key, vector<bool>& visited) {
        visited[key] = true;
        for (int mynewkey : rooms[key]) {
            if (visited[mynewkey] == 0) {
                dfs(rooms, mynewkey, visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        for (int key : rooms[0]) {
            dfs(rooms, key, visited);
        }
        for (bool each : visited) {
            if (each == false) {
                return false;
            }
        }
        return true;
    }
};