class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        unordered_map<char, int> s1, s2;
        for (int i = 0; i < word1.length(); ++i) {
            s1[word1[i]] ++;
            s2[word2[i]] ++;
        }
        if (s1.size() != s2.size()) return false;        unordered_set<char> a1(word1.begin(), word1.end());
        unordered_set<char> a2(word2.begin(), word2.end());
        if (a1 != a2) {return false;}

        vector<int> freq1, freq2;
        for (auto occur : s1) {
            freq1.push_back(occur.second);
        }
        for (auto occur : s2) {
            freq2.push_back(occur.second);
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2;
    }
};