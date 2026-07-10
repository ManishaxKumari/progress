class Solution {
public:
//tabulation
    int longestCommonSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0)); // because dp[i][j]= till i lenghth and j lenght what is my lcs !! so for n and m length  i need n+1,m+1 matrix;
        // base case ki jarrurt nhi h kyuko 0 se already feel h dp[i][0] and dp[0][j] agar ak string ka len bhi 0 hua to koi matching nhi hogi
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){ // becuase length 1 means - index 0 and leng 2 means index 1 so min 1
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};