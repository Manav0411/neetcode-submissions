class Solution {
public:
    void f(vector<vector<int>>& ans, vector<int>& cand, int idx, vector<int>& candidates, int target){
        if(target == 0){
            ans.push_back(cand);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            cand.push_back(candidates[i]);
            f(ans,cand,i,candidates,target-candidates[i]);
            cand.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cand;
        f(ans,cand,0,candidates,target);
        return ans;
    }
};