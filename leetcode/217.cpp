class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashtable;
        for (int num : nums) {
            if (hashtable.count(num)) {return true;}
            hashtable[num] = 1;
        }
        return false;
    }
};