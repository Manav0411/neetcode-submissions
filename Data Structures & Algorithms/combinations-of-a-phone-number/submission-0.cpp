class Solution {
public:
    void f(vector<string>& ans, string& s, int idx,unordered_map<char,vector<char>>& mpp,string& digits){
        if(idx == digits.length()){
            ans.push_back(s);
            return;
        }
        vector<char> letter = mpp[digits[idx]];
        for(int i = 0; i < letter.size(); i++){
            s.push_back(letter[i]);
            f(ans,s,idx+1,mpp,digits);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;
        string s;
        unordered_map<char,vector<char>> mpp;
        mpp['2'] = {'a','b','c'};
        mpp['3'] = {'d','e','f'};
        mpp['5'] = {'j','k','l'};
        mpp['4'] = {'g','h','i'};
        mpp['6'] = {'m','n','o'};
        mpp['7'] = {'p','q','r','s'};
        mpp['8'] = {'t','u','v'};
        mpp['9'] = {'w','x','y','z'};
        f(ans,s,0,mpp,digits);
        return ans;
    }
};
