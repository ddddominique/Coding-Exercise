class Solution {
public:
    int maxArea(vector<int>& height) {
        int l_ptr = 0, r_ptr = height.size() - 1;
        int result = (r_ptr - l_ptr) * min(height[l_ptr], height[r_ptr]);
        while (l_ptr != r_ptr) {
            if (height[l_ptr] <= height[r_ptr]) {
                l_ptr += 1;
            } else {
                r_ptr -= 1;
            }
            int newresult = (r_ptr - l_ptr) * min(height[l_ptr], height[r_ptr]);
            result = result > newresult ? result : newresult;
        }
        return result;
    }
};