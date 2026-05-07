class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currsum=nums[0];
        int best=nums[0];
        for(int i=1;i<n;i++){
            currsum=max(nums[i],nums[i]+currsum);
            best=max(best,currsum);
        }
        return best;
    }
};