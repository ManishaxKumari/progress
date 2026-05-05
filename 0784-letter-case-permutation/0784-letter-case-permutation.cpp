class Solution {
public:
    void solve( vector<string> &ans,string str,string &s,int index){
        //basecase
        if(index==s.size()){
            ans.push_back(str);
            return;
        }
        if(isdigit(s[index])){
            solve(ans, str + s[index], s, index + 1);
        }
        else{
            solve(ans,str+(char)toupper(s[index]),s,index+1);
            solve(ans,str+(char)tolower(s[index]),s,index+1);
        }
        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string str="";
        solve(ans,str,s,0);
        return ans;
    }
};