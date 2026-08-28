class Solution {
public:
    void f(vector<vector<int>>& ans,vector<int>& arr,vector<int>& candidates, int target, int idx){
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        if(target < 0) return;
        for(int i = idx; i < candidates.size(); i++){
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            arr.push_back(candidates[i]);
            f(ans,arr,candidates,target-candidates[i],i+1);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        f(ans,arr,candidates,target,0);
        return ans;
    }
};
