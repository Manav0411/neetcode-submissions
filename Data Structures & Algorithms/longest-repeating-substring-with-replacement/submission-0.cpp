class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mpp(26,0);
        int l = 0, r = 0;
        int maxl = 0;
        int maxf = 0;
        while(r<s.length()){
            mpp[s[r]-'A']++;
            maxf = max(maxf, mpp[s[r]-'A']);
            if((r-l+1)-maxf > k){
                mpp[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxf <= k){
                maxl = max(maxl, r-l+1);
            }
            r++;
        }
        return maxl;
    }
};