class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxp=0;
        int minp=prices[0];
        for(int i=1;i<n;i++){
            maxp=max(maxp,prices[i]-minp);
            minp=min(minp,prices[i]);
        }
        return maxp;
    }
};