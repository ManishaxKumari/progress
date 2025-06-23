class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int sell=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]>sell){
                sell=prices[i];
            }
            else if(prices[i]<sell){
                int buy=prices[i];
                maxprofit=max(maxprofit,sell-buy);
            }
        }
        return maxprofit;
    }
};