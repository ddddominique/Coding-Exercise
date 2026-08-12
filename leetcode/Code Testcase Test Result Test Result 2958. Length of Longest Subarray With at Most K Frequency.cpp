class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int result = 0;
        int counter = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int curr = nums[i];
            if (freq[curr] < k) {
                counter++;
                freq[curr]++;
            } else {
                result = max(result, counter);
                while (freq[curr] >= k) {
                    counter--;
                    freq[nums[left]]--;
                    left++;
                }
                counter++;
                freq[curr]++;

            }
        }
        result = max(result, counter);
        return result;
    }
};
