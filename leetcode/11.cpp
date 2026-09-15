class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (left < right) {
            int mywidth = right - left;
            int myheight = min(height[left], height[right]);
            result = max(result, mywidth * myheight);
            if (myheight == height[left]) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};