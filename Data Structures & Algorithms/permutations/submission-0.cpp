class Solution {
public:
    void f(vector<vector<int>>&ans, vector<int>&curr, vector<bool>& state, vector<int>& nums){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
        }
        for(int i = 0;i < nums.size(); i++){
            if(state[i] == false) continue;
            curr.push_back(nums[i]);
            state[i] = false;
            f(ans,curr,state,nums);
            curr.pop_back();
            state[i] = true;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> curr;
        vector<bool> state(n,true);
        f(ans,curr,state,nums);
        return ans;
    }
};
