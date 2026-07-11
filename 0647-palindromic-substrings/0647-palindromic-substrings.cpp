class Solution {
public:
    int cnt=0;
    bool ispalindromic( string &s , int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(string &s, int idx) {
        if(idx == s.size()) return;
        for(int i = idx; i < s.size(); i++) {
            if(ispalindromic(s,idx,i)){
                cnt++;
            }      
        }

        solve(s, idx + 1);
    }
    int countSubstrings(string s) {
        solve(s,0);
        return cnt;
    }
};