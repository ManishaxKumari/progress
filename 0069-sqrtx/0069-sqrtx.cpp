class Solution {
public:
    int mySqrt(int x) {
        long long low=1,high=x;
        while(low<=high){
        long long mid=(low+high)/2;
        long long num=mid*mid;
        if(num <=x){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
      }
      return high;
    }
};