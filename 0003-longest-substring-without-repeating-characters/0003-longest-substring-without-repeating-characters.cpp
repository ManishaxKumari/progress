class Solution {
public:
    bool check(const unordered_map<char,int> &mpp){
        for(const auto &i:mpp){
            if(i.second>1){
                return true;
            }
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mpp;
        int ans=0;
        int l=0;
        for(int r=0;r<n;r++){
            mpp[s[r]]++;
            if(check(mpp)){
                mpp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};