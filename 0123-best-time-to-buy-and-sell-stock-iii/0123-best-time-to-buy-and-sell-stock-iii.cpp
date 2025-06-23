class Solution {
public:
    int func(vector<int>& arr,int n,int ind,int buy,int trans,vector<vector<vector<int>>> &dp){
        //base case
        if(ind==n || trans==0){
            return 0;
        }
        int maxp=0;
        //buy nhi kiya abhi tak ab karo
        if(dp[ind][buy][trans] !=-1){
            return dp[ind][buy][trans];
        }
        if(buy==0){
            int buyIt=(-1)*arr[ind] + func(arr,n,ind+1,1,trans,dp);
            int NotBuy=func(arr,n,ind+1,0,trans,dp);
            maxp=max(buyIt,NotBuy);
        }
        // buy kar liya ab sell karo
        if(buy==1){
            int sell=arr[ind] + func(arr,n,ind+1,0,trans-1,dp);
            int Notsell=func(arr,n,ind+1,1,trans,dp);
            maxp=max(sell,Notsell);
        }
        return dp[ind][buy][trans]=maxp;

    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        if(n==0) return 0;
        int ans=func(arr,n,0,0,2,dp);
        return ans;
    }
};