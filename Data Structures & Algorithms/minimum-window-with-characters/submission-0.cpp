class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0;
        int j = 0;
        int cnt = 0; int sIdx = -1;
        int maxL = INT_MAX;
        vector<int> mpp(256,0);
        for(char c : t) mpp[c]++;
        while(j<s.length()){
            if(mpp[s[j]] > 0) cnt++;
            mpp[s[j]]--;

            while(cnt == t.size()){
                if(j-i+1 < maxL){
                    maxL = j-i+1;
                    sIdx = i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]] > 0) cnt--;
                i++;
            }
            j++;
        }
        return sIdx == -1 ?  "" : s.substr(sIdx,maxL);
    }
};
