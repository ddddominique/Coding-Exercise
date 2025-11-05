class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double window_avg = 0;
        double max_avg = 0;

        //First window_abg
        for (int i = 0; i < k; ++i) {
            window_avg += nums[i] * 1.0;
        }
        max_avg = window_avg/k;

        //Slide the window
        for (int i = k; i < nums.size(); ++i) {
            window_avg += nums[i] - nums[i - k];
            max_avg = max(max_avg, window_avg/k);
        }
        return max_avg;
    }
};