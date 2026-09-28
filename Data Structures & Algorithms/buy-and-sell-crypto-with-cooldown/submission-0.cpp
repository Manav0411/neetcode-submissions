class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        dp[n][1] = 0;
        dp[n][0] = 0;
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy == 1) {
                    int take = -prices[idx] + dp[idx + 1][0];
                    int ntake = 0 + dp[idx + 1][1];
                    profit = max(take, ntake);
                } else {
                    int t = prices[idx] + dp[idx + 2][1];
                    int nt = 0 + dp[idx + 1][0];
                    profit = max(t, nt);
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};