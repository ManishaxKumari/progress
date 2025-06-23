class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(); // Kitne din ke prices diye gaye hain
        int maxp=0;// Yeh profit store karne ke liye variable hai

        //day 1 se leker end tak jana h 
        for(int i=1;i<n;i++){
            //agar aj ka price prev day se jyada h -> profit hoga
            if(prices[i]>prices[i-1]){
                maxp+=prices[i]-prices[i-1];
            }
            //agar aj ka price prev day ke price se kam h to profit nhi hoga kuch mat kro
            
        }
        return maxp;
        //Jahan bhi price upar gaya, wahan kal kharidke aaj bechne ka socho.
        

    }
};