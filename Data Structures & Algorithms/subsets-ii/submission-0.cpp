class Solution {
public:
    void f(vector<vector<int>>& ans,vector<int>& curr, int idx, vector<int>& nums){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        
        curr.push_back(nums[idx]);
        f(ans,curr,idx+1,nums);
        curr.pop_back();
        int next = idx + 1;
        while (next < nums.size() && nums[next] == nums[idx]) {
            next++;
        }
        f(ans,curr,next,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        f(ans,curr,0,nums);
        return ans;
    }
};
