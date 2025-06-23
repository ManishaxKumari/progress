class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=prices[0];
        int maxp=0;
        for(int i=1;i<n;i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            else{
                maxp=maxp+(prices[i]-buy);
                buy=prices[i];
            }
        }
        return maxp;
    }
};