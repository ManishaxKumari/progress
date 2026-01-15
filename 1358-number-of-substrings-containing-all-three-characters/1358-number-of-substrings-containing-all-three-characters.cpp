class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans[3]={0,0,0};
        int cnt=0;
        int n=s.size();
        int l=0;
        for(int r=0;r<n;r++){
            ans[s[r]-'a']++;
            while(ans[0]>0 && ans[1]>0 && ans[2]>0){
                cnt+=n-r;
                ans[s[l]-'a']--;
                l++;
            }
        }
        return cnt;
    }
};