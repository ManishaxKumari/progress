class Solution {
public:
    void func(int open,int close,int index,int n,string str,vector<string> &ans){
        if(index>2*n || open>n || close>open) return;
        if(index==2*n){
            ans.push_back(str);
            return;
        }
        func(open+1,close,index+1,n,str+'(',ans);
        func(open,close+1,index+1,n,str+')',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        func(0,0,0,n,"",ans);
        return ans;
    }
};