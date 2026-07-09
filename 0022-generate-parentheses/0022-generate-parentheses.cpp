class Solution {
public:
    void solve(vector<string> &ans,string str , int n,int open,int close){
        if(close>open || open>n) return;
        if(open==close && str.size()==2*n){
            ans.push_back(str);
            return;
        }
        solve(ans,str+'(',n,open+1,close);
        solve(ans,str+')',n,open,close+1);
    }
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
       string str="";
       int open=0;
       int close=0;
       solve(ans,str,n,open,close);
       return ans; 
    }
};