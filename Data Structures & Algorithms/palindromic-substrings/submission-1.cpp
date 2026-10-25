
class Solution {
public:
    vector<vector<int>> dp;

    bool check(string& st, int i, int j) {
        if (i >= j) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (st[i] == st[j]) {
            return dp[i][j] = check(st, i + 1, j - 1);
        }

        return dp[i][j] = false;
    }

    int countSubstrings(string s) {
        int n = s.length();
        dp.assign(n, vector<int>(n, -1));

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s, i, j)) cnt++;
            }
        }

        return cnt;
    }
};
