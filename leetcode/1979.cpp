class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = nums[0];
        int big = nums[0];
        for (int num : nums) {
            if (num < small) {
                small = num;
            }
            if (num > big) {
                big = num;
            }
        }
        return gcd(small, big);
    }
};