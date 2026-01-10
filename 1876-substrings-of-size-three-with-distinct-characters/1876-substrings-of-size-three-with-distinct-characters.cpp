class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int>mpp;
        if(s.size()<3) return 0;
        for(int i=0;i<3;i++){
            mpp[s[i]]++;
        }
        int l=0;
        int r=2;
        int cnt=0;
        while(r<s.size()){
            if(mpp[s[l]]==1 && mpp[s[l+1]]==1 && mpp[s[r]]==1){
                cnt++;
            }
            mpp[s[l]]--;
            l++;
            r++;
            mpp[s[r]]++;
        }
        return cnt;
    }
};