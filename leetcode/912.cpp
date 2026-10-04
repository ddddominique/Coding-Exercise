class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergesort(vector<int>& nums, int left, int right) {
        if (left >= right) return; // base case
        int mid = left + (right - left) / 2;
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);

        merge(nums, left, right, mid);
    }
    void merge(vector<int>& nums, int left, int right, int mid) {
        vector<int> sorted;
        int i = left;
        int j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                sorted.push_back(nums[i]);
                i++;
            } else {
                sorted.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) {
            sorted.push_back(nums[i]);
            i++;
        }
        while (j <= right) {
            sorted.push_back(nums[j]);
            j++;
        }
        for (int k = 0; k < sorted.size(); ++k) {
            nums[left + k] = sorted[k];
        }
    }
};