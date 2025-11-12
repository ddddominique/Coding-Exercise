class Solution {
    void dfs(int room_num, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[room_num] = true;
        for (int key : rooms[room_num]) {
            if (!visited[key]) {
                dfs(key, rooms, visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(0, rooms, visited);

        for (bool yes : visited) {
            if (yes == false) {return false;}
        }
        return true;
    }
};