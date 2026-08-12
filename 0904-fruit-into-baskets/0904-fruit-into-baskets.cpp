class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>mpp;
        int ans=0;
        int l=0;
        for(int r=0;r<n;r++){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};