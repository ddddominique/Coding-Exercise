class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {return 0;}

        int curr = 0;
        int best = 0;

        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];

            curr = max(curr + diff, diff);
            best = max(best, curr);
        }
        return best;
    }
};
