class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0; int j =0;
        int maxL = 0;
        unordered_set<char> st;
        while(j<n){
            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            if(!st.count(s[j])){
                st.insert(s[j]);
                maxL = max(maxL,j-i+1);
            }
            j++;
        }
        return maxL;
    }
};
