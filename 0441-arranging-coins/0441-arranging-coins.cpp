class Solution {
public:
    int arrangeCoins(int n) {
        int row=0;
        int cnt=0;
        while(n-row>0){
            row++;
            n=n-row;

        }
        return row;
    }
};