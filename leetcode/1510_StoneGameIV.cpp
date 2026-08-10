class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        dp[0] = false;
        dp[1] = true;
        dp[2] = false;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                int remaining = i - j * j;
                if (dp[remaining] == false) {
                    dp[i] = true;
                    break;
                } else {dp[i] = false;}
            }
        }
        return dp[n];
    }
};