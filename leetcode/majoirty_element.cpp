class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ump;
        for (int num : nums) {
            ump[num]++;
        }
        int result = INT_MIN;
        int realresult;
        for (auto pair : ump) {
            if (pair.second > result) {
                realresult = pair.first;
                result = pair.second;
            }
        }
        return realresult;
    }
};
