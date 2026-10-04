class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int cand = 0;
        for (int num : nums) {
            if (count == 0) {cand = num; count++;}
            else if (cand == num) count++;
            else count--;
        }
        return cand;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    int helper(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + (right - left) / 2;
        int leftmaj = helper(nums, left, mid);
        int rightmaj = helper(nums, mid + 1, right);
        if (leftmaj == rightmaj) return leftmaj;
        int leftcount = 0;
        int rightcount = 0;
        for (int num: nums) {
            if (num == leftmaj) leftcount++;
            if (num == rightmaj) rightcount++;
        }
        return leftcount > rightcount ? leftmaj : rightmaj;
    }
};