class Solution {
public:
    bool ispalind(string s){
        int i = 0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void f(vector<vector<string>>& ans, vector<string>& curr, string s,int idx){
        if(idx == s.length()){
            ans.push_back(curr);
            return;
        }
        for(int i = idx; i < s.length(); i++){
            string str = s.substr(idx,i-idx+1);
            if(ispalind(str)){
                curr.push_back(str);
                f(ans,curr,s,i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        f(ans,curr,s,0);
        return ans;
    }
};
