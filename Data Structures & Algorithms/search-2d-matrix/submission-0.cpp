class Solution {
    private:
    bool solve(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0; int r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();  //rows
        int m = matrix[0].size();  ///col
        for(int i = 0; i < n; i++){
            if(matrix[i][0] <= target && matrix[i][m-1] >= target){
                return solve(matrix[i],target);
            }
        }
        return false;
    }
};
