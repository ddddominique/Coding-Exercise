class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> myset;
        int result = 0;
        for (string deadend : deadends) {
            myset.insert(deadend);
        }
        queue<string> myq;
        if (myset.count("0000")) return -1;
        myq.push("0000");
        while (!myq.empty()) {
            int count = myq.size();
            for (int j = 0; j < count; ++j) {
                string currstr = myq.front();
                myq.pop();
                if (currstr == target) return result;
                myset.insert(currstr);
            for (int i = 0; i < 4; ++i) {
                // 0001 0010 0100 1000
                // 0009 0090 0900 9000
                string forward = currstr;
                string back = currstr;
                forward[i] = (currstr[i] - '0' + 1) % 10 + '0';
                back[i] = (currstr[i] - '0' + 9) % 10 + '0';
                if (!myset.count(forward)) {
                    myset.insert(forward);
                    myq.push(forward);
                }
                if (!myset.count(back)) {
                    myset.insert(back);
                    myq.push(back);
                }

            }
            }

            result++;
        }
        return -1;
    }
};