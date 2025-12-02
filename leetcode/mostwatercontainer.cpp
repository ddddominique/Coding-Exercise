class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (left < right) {
            int curr_area = (right - left) * min(height[left], height[right]);
            result = max(result, curr_area);
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return result;
    }
};