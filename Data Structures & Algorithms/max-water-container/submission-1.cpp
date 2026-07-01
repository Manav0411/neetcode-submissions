class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        int i = 0; int j = n-1;
        while(i<j){
            int side = min(heights[i],heights[j]);
            int wid = j-i;
            ans = max(ans,side*wid);
            if(heights[i] < heights[j]){ i++; continue;}
            else{ j--; continue;}
        }
        return ans;
    }
};
