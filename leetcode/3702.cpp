class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0;
        int len = nums.size();
        bool nonzero = false;
        for (int n : nums) {
            if (n > 0) {nonzero = true;}
            total ^= n;
        }
        if (total != 0) return len;
        if (nonzero) return len - 1;
        return 0;
    }
};
