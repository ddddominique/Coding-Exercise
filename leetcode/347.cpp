class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        for (auto& pair : map) {
            heap.push({pair.second, pair.first});
        }
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
    }
};