class Solution {
    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c== 'o' || c == 'i' || c == 'u';
    }
public:
    string reverseVowels(string s) {
        vector<int> index;
        for (int i = 0; i < s.size(); ++i) {
            if (isvowel(tolower(s[i]))) {
                index.push_back(i);
            }
        }
        for (int i = 0; i < index.size() / 2; ++i) {
            char temp = s[index[i]];
            s[index[i]] = s[index[index.size() - 1 - i]];
            s[index[index.size() - 1 - i]] = temp;
        }
        return s;
    }
};