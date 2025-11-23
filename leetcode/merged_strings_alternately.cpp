class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int len1 = word1.size();
        int len2 = word2.size();
        int small = min(len1, len2);
        for (int i = 0; i < small; ++i) {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        if (len1 == small) {
            result += word2.substr(small);
        } 
        if (len2 == small) {
            result += word1.substr(small);
        }
        return result;
    }
};