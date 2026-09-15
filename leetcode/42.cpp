class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftmax = 0;
        int rightmax = 0;
        int result = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                // left wall is the limit
                if (height[left] > leftmax) {
                    leftmax = height[left];
                } else {
                    result += leftmax - height[left];
                }
                left++;
            } else {
                if (height[right] > rightmax) {
                    rightmax = height[right];
                } else {
                    result += rightmax - height[right];
                }
                right--;
            }
        }
        return result;
    }
};