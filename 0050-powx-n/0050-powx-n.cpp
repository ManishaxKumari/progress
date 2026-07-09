class Solution {
public:
    double solve(double x, long long n){
        if(n==0) return 1.0;
        if(n%2==0){ //even
            return solve(x*x,n/2);
        }
        else {
            return x* solve(x,n-1);
        }
    }
    double myPow(double x, int n) {
        long long num=n;
        if(num<0){
            return solve(1.0/x,-1*num);
        }
        else{
            return solve(x,num);
        }
        
    }
};