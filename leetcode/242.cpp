class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> hashtable;
        for (char c : s) {
            hashtable[c]++;
        }
        for (char c : t) {
            if (!hashtable[c]) {return false;}
            hashtable[c]--;
        }
        return true;
    }
};