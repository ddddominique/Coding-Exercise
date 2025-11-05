class Solution {
public:
    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int window_max = 0;
        int real_max = 0;

        for (int i = 0; i < k; ++i) {
            window_max += isvowel(s[i]);
        }
        real_max = window_max;
        for (int i = k; i < s.length(); ++i) {
            window_max += isvowel(s[i]) - isvowel(s[i - k]);
            real_max = max(window_max, real_max);
        }
        return real_max;
    }
};