class Solution {
public:
    int missingInteger(vector<int>& nums) {
        //find i
        if (nums.size() == 1) return nums[0] + 1;
        int i = -1;
        for (int j = 1; j < nums.size();++j) {
            if (nums[j] != nums[j - 1] + 1) {
                i = j;
                break;
            }
        }
        if (i == -1) i = nums.size();
        int result = 0;
        for (int j = 0; j < i; ++j) {
            result += nums[j];
        }
        sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size(); ++j) {
            if (result == nums[j]) {
                result += 1;
            }
        }
        return result;

    }
};
