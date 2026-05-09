class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hasht1;
        unordered_map<char, char> hasht2;
        if (s.length()!= t.length()) return false;
        for (int i = 0; i < s.length(); ++i) {
            if (hasht1.count(s[i]) && hasht1[s[i]] != t[i]) return false;
            if (hasht2.count(t[i]) &&  hasht2[t[i]] != s[i]) return false;
            hasht1[s[i]] = t[i];
            hasht2[t[i]] = s[i];


        }
        return true;
    }
};
