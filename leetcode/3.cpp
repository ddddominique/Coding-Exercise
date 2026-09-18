class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int left = 0;
        unordered_map<char, int> map;
        for (int right = 0; right < s.length(); ++right) {
            if (map[s[right]] == 1) {
                while (map[s[right]] == 1) {
                    map[s[left]] = 0;
                    left++;
                }
            }
            result = max(result, right - left + 1);
            map[s[right]] = 1;
        }
        return result;
    }
};