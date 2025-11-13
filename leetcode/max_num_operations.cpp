class Solution {
    bool operation(string& s) {
        int result = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if (i == n - 1) {return 0;}
            if (s[i] == '1' && s[i + 1] == '0') {
                int add = i + 1;
                while(add < n && s[add] != '1') {
                    add += 1;
                }
                s[i] = '0';
                s[add - 1] = '1';
                return 1;
            }
        }
        return 0;
    }
public:
    int maxOperations(string s) {
        int count = 0;
        while (operation(s)) {
            count += 1;
        }
        return count;
    }
};