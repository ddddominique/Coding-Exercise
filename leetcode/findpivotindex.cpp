class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left_sum(nums.size());
        vector<int> right_sum(nums.size());
        left_sum[0] = 0;
        right_sum[nums.size() - 1] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            left_sum[i] = left_sum[i - 1] + nums[i - 1];
            right_sum[nums.size() - 1 - i] = right_sum[nums.size() - i] + nums[nums.size()  - i];
        }

        for (int i = 0; i < left_sum.size(); ++i) {
            if (left_sum[i] == right_sum[i]) {
                return i;
            }
        }
        return -1;
    }
};