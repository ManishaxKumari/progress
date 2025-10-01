class Solution {
public:
    bool ispossible( long long mid,int x){
        long long num=mid*mid;
        if(num<=x){
            return true;
        }
        return false;
    }
    int mySqrt(int x) {
        long long low=1;
        long long high=x;
        int ans=0;
        while(low<=high){
            long long mid=(low+high)/2;
            if(ispossible(mid,x)){
                ans=mid;
                low=mid+1; // ye ans possible h but or higher sidr jaker dekho
            }
            else{
                high=mid-1; // left side jao bhut bada ho gya mid
            }
        }
        return ans;
    }
    
};