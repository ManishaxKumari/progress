class Solution {
public:
    //---------recursion------------------

    // int fib(int n) {
    //     if(n<=1) return n;
    //     return fib(n-1)+fib(n-2);
    // }

    //----------------------------------memorization--------------------------

    // int solve(int n,vector<int> &dp){
    //     if(n<=1) return n;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    // }
    // int fib(int n){
    //     vector<int>dp(n+1,-1);
    //     return solve(n,dp);
    // }

    //-----------------------tabulation--------------------------------------

    // int fib(int n){
    //     if(n<=1) return n;
    //     vector<int>dp(n+1);
    //     dp[0]=0;
    //     dp[1]=1;

    //     for(int i=2;i<n+1;i++){
    //         dp[i]=dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }

    //-------------space optimization------------------
    int fib(int n){
        if(n<=1)return n;
        int prev1=0;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int temp=prev1+prev2;
            prev1=prev2;
            prev2=temp;
        }
        return prev2;
    }


};