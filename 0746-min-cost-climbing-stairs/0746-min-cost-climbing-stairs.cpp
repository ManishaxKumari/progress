class Solution {
public:
//recusrion
    int solve(vector<int>&dp,vector<int>& cost,int n){
        if(n<=1) return cost[n];
        if(dp[n]!=-1) return dp[n];
        return dp[n]=cost[n]+min(solve(dp,cost,n-1),solve(dp,cost,n-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0); // because their is no cost to reach top
        int n=cost.size();
        vector<int> dp(n,-1);
        solve(dp,cost,n-1);
        return dp[n-1];
    }
};