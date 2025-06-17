class Solution {
public:
//solve using tabulation (DP)
    // int fib(int n) {
    //     vector<int> dp(n+1);
    //     if(n<=1){
    //         return n;
    //     }
    //     dp[0]=0;
    //     dp[1]=1;
    //     for(int i=2;i<=n;i++){
    //         dp[i]=dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }


// space optimization solve withour dp itetrative
     int fib(int n){
        if(n<=1){
            return n;
        }
        int prev2=0;
        int prev=1;
        for(int i=2;i<=n;i++){
            int curr=prev2+prev;
            prev2=prev;
            prev=curr;
        }
        return prev;
     }
};