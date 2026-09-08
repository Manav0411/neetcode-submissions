class Solution {
public:
    int f(int n, vector<int>& dp){
        if(n==0) return 1;
        if (n==1) return 1;
        if(dp[n] != -1) return dp[n];
        int pick = f(n-1,dp);
        int notp = f(n-2,dp);
        return dp[n] = pick+notp;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};
