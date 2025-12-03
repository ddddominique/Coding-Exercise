class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int counter = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[right] == 0) {
                counter++;
            }
            while (counter > k) {
                if (nums[left] == 0) {
                    counter--;
                }
                left++;
            }
            result = max(result, right - left + 1);
            right++;
            
        }
        return result;
    }
};
