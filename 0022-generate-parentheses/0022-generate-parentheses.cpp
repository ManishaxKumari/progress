class Solution {
public:
    void solve(vector<string> &ans,string str , int n,int open,int close){
        if(open==n && close==n){
            ans.push_back(str);
            return;
        }
        if(open<n){
            solve(ans,str+'(',n,open+1,close);
        }
        if(close<open){
            solve(ans,str+')',n,open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
       string str="";
       solve(ans,str,n,0,0);
       return ans; 
    }
};