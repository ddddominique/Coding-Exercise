class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = 0, ptr2 = 0;
        vector<int> result;
        for (int i = 0; i < m + n; ++i) {
            if (ptr1 == m) {
                result.push_back(nums2[ptr2]);
                ptr2++;
            } else if (ptr2 == n) {
                result.push_back(nums1[ptr1]);
                ptr1++;
            } else if (nums1[ptr1] >= nums2[ptr2]) {
                result.push_back(nums2[ptr2]);
                ptr2++;
            } else {
                result.push_back(nums1[ptr1]);
                ptr1++;
            }
        }
        nums1 =  result;
    }
};