class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // divide and conquer
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> firsthalf(nums.begin(), nums.begin() + n / 2);
        vector<int> secondhalf(nums.begin() + n/2, nums.end());
        int leftmax = maxSubArray(firsthalf);
        int rightmax = maxSubArray(secondhalf);
        int result = max(leftmax, rightmax);
        // 10 9 8 -4 -4 9 10 10
        // i claim that maxcrossover = maxleft start left + maxright start right
        int leftsum = nums[n/2 - 1];
        int sum = 0;
        for (int i = n/2 - 1; i >= 0; --i) {
            sum += nums[i];
            leftsum = max(sum, leftsum);
        }
        sum = 0;
        int rightsum = nums[n/2];
        for (int i = n/2; i < n; ++i) {
            sum += nums[i];
            rightsum = max(sum, rightsum);
        }
        int middlesum = leftsum + rightsum;
        return max(middlesum, result);
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int sum = 0;
        // -3 -4
        for (int num : nums) {
            if (sum < 0) {
                sum = 0;
            }
            sum += num;
            result = max(result, sum);
        }
        return result;
    }
};