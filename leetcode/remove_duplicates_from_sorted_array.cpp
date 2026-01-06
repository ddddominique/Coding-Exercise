class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[ptr - 1]) {
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        return ptr;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0; //pointer to the positions of the unique elements

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[pos] != nums[i]) {
                pos++;
                nums[pos] = nums[i];
            }
        }
        return pos + 1;
    }
};