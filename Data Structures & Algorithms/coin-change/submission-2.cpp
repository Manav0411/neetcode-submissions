class Solution {
   public:
    // int f(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    //     if (idx == 0) {
    //         if (amount % coins[idx] == 0)
    //             return amount / coins[idx];
    //         else
    //             return 1e9;
    //     }
    //     if (dp[idx][amount] != -1) return dp[idx][amount];

    //     int ntake = f(idx - 1, amount, coins, dp);
    //     int take = 1e9;
    //     if (coins[idx] <= amount) take = 1 + f(idx, amount - coins[idx], coins, dp);

    //     return dp[idx][amount] = min(ntake, take);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        }
        for (int idx = 1; idx < n; idx++) {
            for (int am = 0; am <= amount; am++) {
                int ntake = dp[idx - 1][am];
                int take = 1e9;
                if (coins[idx] <= am) take = 1 + dp[idx][am - coins[idx]];

                dp[idx][am] = min(ntake, take);
            }
        }
        return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];
    }
};
