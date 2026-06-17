class Solution {
public:
    int divide(int dividend, int divisor) {
        //edges case
        if(dividend==divisor) return 1;
        if(dividend==INT_MIN && divisor == -1 ) return INT_MAX;
        if(divisor==1) return dividend;

        bool ispositive=((dividend>0 && divisor>0) || (dividend<0 && divisor<0));
        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);

        long long ans=0;
        while(n>=d){
            n-=d;
            ans++;
        }
        if(ans>INT_MAX){
            return ispositive? INT_MAX : INT_MIN;
        }
        return ispositive?ans: -ans;

    }
};