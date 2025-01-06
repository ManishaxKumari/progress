class Solution {
public:
    int arrangeCoins(int n) {
        long long low=1;
        long long high=n;
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long coins=(mid*(mid+1))/2;
            if(coins>n){
                high=mid-1;
            }
            else{
                low=mid+1;
                ans=max(ans,mid);
            }
        }
        return (int)ans;
    }
};