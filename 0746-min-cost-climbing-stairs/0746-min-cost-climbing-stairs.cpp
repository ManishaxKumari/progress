class Solution {
public:
//space optimization
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0); // because their is no cost to reach top
        int n=cost.size();
        vector<int> dp(n);
        //base case
        int prev2=cost[0];
        int prev1=cost[1];
        for(int i=2;i<n;i++){
            int curr=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
};