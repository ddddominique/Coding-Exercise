class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int result = 0;
        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            result = max(result, width * h);
            if (h == height[left]) {left++;}
            else {right--;}
        }
    return result;
    }
};
