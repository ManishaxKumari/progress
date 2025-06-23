class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprices=0;
        int minprices=prices[0];
        for(int i=1;i<n;i++){
            maxprices=max(maxprices,prices[i]-minprices);
            minprices=min(minprices,prices[i]);
        }
        return maxprices;
    }
};