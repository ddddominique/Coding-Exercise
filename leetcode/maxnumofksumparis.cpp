class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> freq;
        for (int num : nums) {
            int complement = k - num;
            if (freq.count(complement) && freq[complement]) {
                result += 1;
                freq[complement] -= 1;
            } else {
                freq[num] += 1;
            }
        }
        return result;
    }
};