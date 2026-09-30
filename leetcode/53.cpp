class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {return nums[0];}
        vector<int> left_half(nums.begin(), nums.begin() + nums.size()/2);
        vector<int> right_half(nums.begin() + nums.size()/2, nums.end());
        int l = maxSubArray(left_half);
        int r = maxSubArray(right_half);
        // claim
        int mid = nums.size() / 2;
        int leftsum = nums[mid - 1];
        int sum = 0;
        for (int i = mid - 1; i >= 0; --i) {
            sum = sum + nums[i];
            leftsum = max(leftsum, sum);
        }
        int rightsum = nums[mid];
        sum = 0;
        for (int i = mid; i < nums.size();++i) {
            sum = sum + nums[i];
            rightsum = max(rightsum, sum);
        }
        int actualsum = leftsum + rightsum;
        if (actualsum > l && actualsum > r) {return actualsum;}
        else if (r > l) {return r;}
        else {return l;}
    }
};