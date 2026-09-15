class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> map(nums.begin(), nums.end());
        int result = 0;
        for (int i : map) {
            if (map.count(i - 1)) {
                continue;
                // not at the start
            }
            int curr = 1;
            while (map.count(i + 1)) {
                curr++;
                i++;
            }
            result = max(result, curr);

        }
        return result;
    }
};