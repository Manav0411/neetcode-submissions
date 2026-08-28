class Solution {
public:
    void f(vector<vector<int>>& ans,vector<int>& arr, 
        int idx, vector<int>& nums){
            if(idx == nums.size()){
                ans.push_back(arr);
                return;
            }
            arr.push_back(nums[idx]);
            f(ans,arr,idx+1,nums);
            arr.pop_back();
            f(ans,arr,idx+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        f(ans,arr,0,nums);
        return ans;
    }
};
