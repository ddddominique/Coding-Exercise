class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 0, left = 0, zero_count = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                zero_count += 1;
            }

            while (zero_count > 1) {
                if (nums[left] == 0) {
                    zero_count -= 1;
                }
                left += 1;
            }
            result = max(result, right - left);
        }
        return result;
    }

};