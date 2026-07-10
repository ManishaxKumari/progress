class Solution {
public:
    vector<vector<string>> ans;
    vector<string>v;
    bool ispalindrome(string s){
        int l=0;
        int r =s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(string s,int idx,string str){
        //base case
        if(idx>=s.size()){
            ans.push_back(v);
        }
        for(int i=idx;i<s.size();i++){
            string sub=s.substr(idx,i-idx+1);
            if(ispalindrome(sub)){
                v.push_back(sub);
                solve(s,i+1,str);
                v.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        string str="";
        solve(s,0,str);
        return ans;
    }
};