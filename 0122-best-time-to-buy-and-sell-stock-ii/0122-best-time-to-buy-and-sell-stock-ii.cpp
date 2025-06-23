class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        int profit=0;
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        dp[n][0] = dp[n][1] = 0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<= 1;buy++) {
                // We can buy the stock
                if(buy==0){ 
                    profit=max(0+dp[ind+1][0], (-1)*prices[ind]+dp[ind+1][1]);
                }
                // We can sell the stock
                if (buy==1) { 
                    profit=max(0+dp[ind+1][1],prices[ind]+dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][0];
        
    }
};