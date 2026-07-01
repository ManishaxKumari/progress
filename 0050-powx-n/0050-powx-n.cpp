class Solution {
public:
    double func(double x , long n){
        if(n<=0){
            return 1.0;
        }
        if(n%2==0){
            return func(x*x,n/2);
        }
        return x*func(x,n-1);
    }

    double myPow(double x, int n) {
        long num=n;
        if(num<0){
            return (1.0/func(x,-1*num));
        }
        return func(x,num);
    }
};