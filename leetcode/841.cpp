class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, false);
        visited[0] = true;
        queue<int> myq;
        myq.push(0);
        while (!myq.empty()) {
            int curr = myq.front();
            myq.pop();
            for (int key : rooms[curr]) {
                if (visited[key] == false) {
                    myq.push(key);
                    visited[key] = true;
                }
            }
        }
        for (bool istrue : visited) {
            if (istrue == false) return false;
        }
        return true;
    }
};