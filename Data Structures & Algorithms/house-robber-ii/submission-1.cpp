class Solution {
   public:
    int f(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int prev = nums[0];
        int prev2 = 0;
        int curr = 0;
        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if (i > 1) pick += prev2;
            int npick = 0 + prev;

            curr = max(pick, npick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        if(nums.size() ==1) return nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(i != 0) temp2.push_back(nums[i]);
            if(i != nums.size()-1) temp1.push_back(nums[i]);
        }
        int ans1 = f(temp1);
        int ans2 = f(temp2);
        return max(ans1,ans2);
    }
};
