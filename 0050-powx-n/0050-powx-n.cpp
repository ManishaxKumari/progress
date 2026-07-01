class Solution {
using ll=long long;
public:
    double func(double x, ll n){
        if(n<=0) return 1.0; //base case
        //choice -> odd/even
        if(n%2==0) return func(x*x,n/2);
        return x*func(x,n-1);
    }
    double myPow(double x, int num) {
        ll n=num;
        //choice n-> positive or negative
        if(n<0) return (1.0/func(x,-1*n));
        return func(x,n);
    }
};