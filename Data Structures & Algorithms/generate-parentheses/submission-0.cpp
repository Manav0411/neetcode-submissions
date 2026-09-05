class Solution {
public:
    void f(vector<string>&ans,string curr, int open, int close,int n){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(open < n){
            curr += '(';
            f(ans,curr,open+1,close,n);
            curr.pop_back();
        }
        if(close < open){
            curr += ')';
            f(ans,curr,open,close+1,n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        f(ans,curr,0,0,n);
        return ans;
    }
};
