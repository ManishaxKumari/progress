class Solution {
public:
    bool subset(vector<int>& nums,int sum,int n, vector<vector<int>> &dp){
         if (sum == 0) return true;
         if (n <= 0) return false;
         if (dp[n][sum] != -1){
            return dp[n][sum];
         }
        if(nums[n-1]>sum){
            return dp[n][sum]=subset(nums,sum,n-1,dp);
        }
        else if(nums[n-1]<=sum){
            return dp[n][sum]=subset(nums,sum-nums[n-1],n-1,dp) || subset(nums,sum,n-1,dp);
        }
        return false;
    }

    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int n=nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        if(sum%2 !=0){
            return false;
        }
        else {
            return subset(nums,sum/2,n,dp);
        }
    }
};