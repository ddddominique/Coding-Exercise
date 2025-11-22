class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0, norob = 0;
        //  
        for (int i = 0; i < nums.size(); ++i) {
            int newrob = norob + nums[i];
            int newnorob = max(rob, norob);
            rob = newrob;
            norob = newnorob;
        }
        return  max(rob, norob);
    }
};
