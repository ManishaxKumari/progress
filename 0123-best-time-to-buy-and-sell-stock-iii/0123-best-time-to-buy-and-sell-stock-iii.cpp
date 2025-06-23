class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                    if(j==0){
                        int buy=(-1)*arr[i] + dp[i+1][1][k];
                        int notbuy=dp[i+1][0][k];
                        dp[i][j][k]=max(buy,notbuy);
                    }
                    if(j==1){
                        int sell=arr[i] + dp[i+1][0][k-1];
                        int notsell=dp[i+1][1][k];
                        dp[i][j][k]=max(sell,notsell);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};