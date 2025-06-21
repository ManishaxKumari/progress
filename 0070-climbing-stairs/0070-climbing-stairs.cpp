class Solution {
public:
//memo
    // int func(int n,vector<int> &dp){
    //     if(n<0) return 0;
    //     if(n==0) return 1;
    //     if(dp[n] !=-1){
    //         return dp[n];
    //     }
    //     return dp[n]=func(n-1,dp) + func(n-2,dp);
    // }
    // int climbStairs(int n) {
    //     vector<int> dp(n+1,-1);
    //     return func(n,dp);
    // }

//tabulation
    int climbStairs(int n){
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
//space optimization

    // int climbStairs(int n) {
    //     int prev2 = 1;
    //     int prev = 1;
    //     for (int i = 2; i <= n; i++) {
    //         int cur_i = prev2 + prev;
    //         prev2 = prev;
    //         prev = cur_i;
    //     }
    //     return prev;

    // }



};