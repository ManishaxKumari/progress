class Solution {
public:
    bool check(const unordered_map<char,int> &mpp){
        for(auto it : mpp){
            if(it.second>1) return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mpp;
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++){
            mpp[s[r]]++;
            while(check(mpp)){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};