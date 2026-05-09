class Solution {
public:
//tabulation
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0); // because their is no cost to reach top
        int n=cost.size();
        vector<int> dp(n);
        //base case
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }

        return dp[n-1];
    }
};