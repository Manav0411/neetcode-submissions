class Solution {
public:
    int f(int id,int n, vector<int>& dp){
        if(id == n) return 1;
        if (id > n) return 0;
        if(dp[id] != -1) return dp[id];
        int pick = f(id+1,n,dp);
        int notp = f(id+2,n,dp);
        return dp[id] = pick+notp;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(0,n,dp);
    }
};
