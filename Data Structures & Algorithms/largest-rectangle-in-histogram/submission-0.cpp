class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxA = 0;
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] > heights[i]){
                int element = s.top(); s.pop();
                int ns = i; int ps = s.empty()?-1:s.top();
                maxA = max(maxA, heights[element]*(ns-ps-1));
            }
            s.push(i);
        }
        while(!s.empty()){
            int ns = n;
            int element = s.top(); s.pop();
            int ps = s.empty()?-1:s.top();
            maxA = max(maxA, heights[element]*(ns-ps-1));
        }
        return maxA;
    }
};