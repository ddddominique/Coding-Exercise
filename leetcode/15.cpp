class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // -4 -1 -1 0 1 2
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= 1 && nums[i] == nums[i - 1]) {continue;}
            // if we see the same number, we already include its triplets
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == -nums[i]) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                } else if (sum < -nums[i]) {
                    l++;
                } else {
                    r--;
                }
            }


        }
        return result;
    }
};