class Solution {
public:
      int func(int ind,int buy,vector<int> &arr,int n,vector<vector<int>> &dp){
        //base case
        if(ind==n){
            return 0;
        }
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }
        int profit=0;
        //we can buy stock
        if(buy==0){ // we hadn't buy anthing prev
            int buyIt=(-1)*arr[ind] + func(ind+1,1,arr,n,dp);
            int notBuyIt=func(ind+1,0,arr,n,dp);
            profit=max(buyIt,notBuyIt);
        }
        //we can sell 
        if(buy==1){ // we had buy previously
            int sell=arr[ind] + func(ind+1,0,arr,n,dp);
            int notSell=func(ind+1,1,arr,n,dp);
            profit=max(sell,notSell);
        }
        return dp[ind][buy]=profit;

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans=func(0,0,prices,n,dp);
        return ans;
    }
};