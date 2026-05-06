class Solution {
public:
    int solve(int n,vector<int> &dp){
        //base case
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n]; // already precompute - reuse here
        return dp[n]=solve(n-1,dp) + solve(n-2,dp);

    }
    int fib(int n) {
        vector<int>dp(n+1,-1); // memorization
        return solve(n,dp);
    }
};