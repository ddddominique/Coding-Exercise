class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            int last_ele = arr1[arr1.size() - 1];
            int last_ele_2 = arr2[arr2.size() - 1];
            if (last_ele > last_ele_2) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        vector<int> result = arr1;
        result.insert(result.end(), arr2.begin(), arr2.end());

        return result;
    }
};