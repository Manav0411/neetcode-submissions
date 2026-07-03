class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        unordered_map<char, int> mpp;
        for (char c : s1) {
            mpp[c]++;
        }
        unordered_map<char, int> mpp1;
        int i = 0;
        int j = 0;
        while (j < m) {
            while (j - i + 1 > n) {
                mpp1[s2[i]]--;
                if (mpp1[s2[i]] == 0)
                    mpp1.erase(s2[i]);
                i++;
            }
            if (j - i + 1 <= n) {
                mpp1[s2[j]]++;
                if (j - i + 1 == n) {
                    if (mpp == mpp1)
                        return true;
                }
            }
            j++;
        }
        return false;
    }
};