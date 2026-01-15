class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mpp;
        int cnt=0;
        int n=s.size();
        int l=0;
        for(int r=0;r<n;r++){
            mpp[s[r]]++;
            while(mpp.size()==3){
                cnt+=n-r;
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
        }
        return cnt;
    }
};