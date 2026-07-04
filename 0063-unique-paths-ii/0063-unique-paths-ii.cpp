class Solution {
public:
//memorization
    int solve(int i,int j,vector<vector<int>>& Grid,vector<vector<int>> &dp){
        //base case
        if(i>=0 && j>=0 && Grid[i][j]==1 ) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(i-1,j,Grid,dp);
        int left=solve(i,j-1,Grid,dp);
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n=Grid.size();
        int m=Grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,Grid,dp);
    }
};