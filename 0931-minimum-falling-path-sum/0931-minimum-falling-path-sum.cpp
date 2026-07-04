class Solution {
public:
//tabulation
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    dp[0][j]=matrix[0][j];
                    continue;
                }
                int up=matrix[i][j]+dp[i-1][j];
                int leftDia=1e9;
                int RightDia=1e9;
                if(j-1>=0){
                    leftDia=matrix[i][j]+dp[i-1][j-1];
                }
                if(j+1<m){
                    RightDia=matrix[i][j]+dp[i-1][j+1];
                }
                dp[i][j]=min({up,leftDia,RightDia});
            }
        }

        int mini = INT_MAX;
        for(int j=0;j<m;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};