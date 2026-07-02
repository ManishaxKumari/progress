class Solution {
public:
    bool ispalindrome(string &s,int idx,int i){
        int l=idx;
        int r=i;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(string &s,vector<vector<string>> &ans,vector<string> &temp,int idx){
        if(idx>=s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(ispalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                solve(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans; //store the final answer
        vector<string> temp; // to make string
        solve(s,ans,temp,0);
        return ans;
    }
};