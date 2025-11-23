class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN; //bought state
        int sell = 0; //sold state
        for (int price : prices) {
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
        }
        return sell;
    }
};