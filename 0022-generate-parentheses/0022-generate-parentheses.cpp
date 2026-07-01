class Solution {
public:
    void func(int open,int close,int n,string &str,vector<string> &ans){
        if(open==n && close==n){ //valid state
            ans.push_back(str);
            return;
        }
        if(open<n){
            str.push_back('(');
            func(open+1,close,n,str,ans);
            str.pop_back();
        }
        if(close<open){
            str.push_back(')');
            func(open,close+1,n,str,ans);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str = "";
        func(0, 0, n, str, ans);
        return ans;
    }
};