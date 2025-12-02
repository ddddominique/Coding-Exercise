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

class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c== 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int result = 0;
        int curr_max = 0;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                curr_max++;
            }
        }

        result = curr_max;
        
        for (int i = k; i < s.size(); ++i) {
            curr_max += isVowel(s[i]) - isVowel(s[i - k]);
            result = max(result, curr_max);
            
        }
        return result;
    }
};