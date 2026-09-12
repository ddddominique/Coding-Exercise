class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // -2 -1 0 0 1 2
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= 1 && nums[i] == nums[i - 1]) {continue;}
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j >= i + 2 && nums[j] == nums[j - 1]) {continue;}
                int l = j + 1;
                int r = nums.size() - 1;
                long long need = (long long)target - nums[i] - nums[j];
                while (l < r) {
                    long long sum = (long long)nums[l] + nums[r];
                    if (sum == need) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l - 1]) {
                            l++;
                        }
                        while (l < r && nums[r] == nums[r + 1]) {
                            r--;
                        }
                    } else if (sum < need) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return result;
    }
};