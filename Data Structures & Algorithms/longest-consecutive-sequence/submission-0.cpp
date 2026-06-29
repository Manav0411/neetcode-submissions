class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto& it : nums){
            st.insert(it);
        }
        int ans =0;
        for(auto ele : st){
            if(st.count(ele-1) == 0){
                int cnt = 1;
                int x = ele+1;
                while(st.count(x)){
                    cnt++;
                    x++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};