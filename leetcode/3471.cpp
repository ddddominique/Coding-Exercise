class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i <= nums.size() - k; ++i) {
            unordered_map<int, bool> visited;
            for (int j = 0; j < k; ++j) {
                if (!visited[nums[i + j]]) {
                    freq[nums[i + j]] += 1;
                    visited[nums[i + j]] = true;
                }
            }
        }
        int result = -1;
        for (auto& pair : freq) {
            if (pair.second == 1) {
                result = max(result, pair.first);
            }
        }
        return result;
    }
};