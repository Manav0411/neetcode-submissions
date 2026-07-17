class Solution {
   private:
    int helper(int mid, vector<int>& piles) {
        int ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            int val = ceil(double(piles[i]) / mid);
            ans += val;
        }
        return ans;
    }

   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = helper(mid, piles);
            if (val > h)
                l = mid + 1;
            else {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};
