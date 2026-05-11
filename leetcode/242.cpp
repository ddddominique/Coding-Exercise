class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.length() != s.length()) return false;
        unordered_map<char, int> mymap;
        for (char c : s) {
            mymap[c]++;
        }
        for (char c : t) {
            if (!mymap[c]) return false;
            mymap[c]--;
        }
        return true;
    }
};
