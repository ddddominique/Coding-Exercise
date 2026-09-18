class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if (prices.size() == 1) return result;
        int left = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[left] < prices[i]) {
                result = max(result, prices[i] - prices[left]);
            } else {
                left = i;
            }
        }
        return result;
    }
};