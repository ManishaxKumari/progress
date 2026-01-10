class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int n=nums.size();
        int ans=0;
        int cntzero=0;
        for(int r=0;r<n;r++){
            if(nums[r]==0) cntzero++;
            while(cntzero>k){
                if(nums[l]==0) cntzero--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};