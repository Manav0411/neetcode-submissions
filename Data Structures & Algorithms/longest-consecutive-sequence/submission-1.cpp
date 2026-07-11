class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int it : nums){
            s.insert(it);
        }
        int ans = 0;
        int i = 0;
        while(i < nums.size()){
            int cnt = 1;
            if(s.count(nums[i]-1)){ i++; continue;}
            else{
                int curr = nums[i];
                while(s.count(curr+1)){ cnt++; curr++;}
                ans = max(ans,cnt);
            }
            i++;
        }
        return ans;
    }
};
