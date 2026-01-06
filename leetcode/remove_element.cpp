class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int result = 0;
        vector<int> myresult;
        for (int i : nums) {
            if (i != val) {
                result++;
                myresult.push_back(i);
            }
        }
        nums = myresult;
        return result;
    }
};