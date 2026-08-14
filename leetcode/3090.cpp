class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int left = 0;
        int result = 0;
        for (int right = 0; right < s.length(); ++right) {
            freq[s[right]]++;
            if (freq[s[right]] > 2) {
                while (s[left] != s[right]) {
                    freq[s[left]]--;
                    left++;
                }
                freq[s[left]]--;
                left++;

            }
            result = max(result, right - left + 1);

        }
        return result;
    }
};
