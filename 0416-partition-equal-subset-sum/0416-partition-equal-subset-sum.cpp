class Solution {
public:
    bool solve(vector<int>& nums,int idx,int target,vector<vector<int>> &dp){
        if(target==0) return true;
        if(idx==0){
            return target==nums[idx];
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool nottake=solve(nums,idx-1,target,dp);
        bool take=false;
        if(nums[idx]<=target){
            take=solve(nums,idx-1,target-nums[idx],dp);
        }
        return dp[idx][target]=nottake || take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum % 2)!=0) return false;
        int target=(sum/2);
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(nums,n-1,target,dp);
    }
};