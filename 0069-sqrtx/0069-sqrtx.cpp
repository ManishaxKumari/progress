class Solution {
public:
    using ll=long long;
    int mySqrt(int x) {
        ll low=0;
        ll high=x;
        while(low<=high){
            ll mid=(low+high)/2;
            ll ans=mid*mid;
            ll target=x;
            if(ans == target) return (int)mid;
            else if(ans<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return (int)high;
    }
};