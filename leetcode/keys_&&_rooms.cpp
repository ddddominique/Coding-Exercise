class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> s;
        s.insert(0);
        for (int i = 0; i < rooms.size(); ++i) {
            if (s.count(i)) {
                for (int j = 0; j < rooms[i].size(); ++j) {
                    s.insert(rooms[i][j]);
                }
            } else {
                return false;
            }
        }
        return true;
    }
};