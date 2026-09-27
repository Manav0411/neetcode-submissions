class Solution {
public:
    int f(int idx, int amount, vector<int>& coins,vector<vector<int>>& dp){
        if(idx == 0){
            if(amount%coins[idx] == 0) return amount/coins[idx];
            else return 1e9;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];

        int ntake = f(idx-1,amount,coins,dp);
        int take = 1e9;
        if(coins[idx] <= amount) take = 1 + f(idx,amount-coins[idx],coins,dp);

        return dp[idx][amount] = min(ntake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp) == 1e9 ? -1 : f(n-1,amount,coins,dp);
    }
};
