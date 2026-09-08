class Solution {
public:
    int f(int idx, vector<int>& dp, vector<int>&cost){
        if(idx == 0) return 0;
        if(idx == 1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int ones = f(idx-1,dp,cost)+cost[idx-1];
        int twos = INT_MAX;
        if(idx > 1) twos = f(idx-2,dp,cost)+cost[idx-2];

        return dp[idx] = min(ones,twos);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return f(n,dp,cost);
    }
};
