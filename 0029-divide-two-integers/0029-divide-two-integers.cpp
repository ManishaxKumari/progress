class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // Edge cases
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        bool isPositive =!((dividend >= 0 && divisor < 0) ||(dividend <= 0 && divisor > 0));
        long n = dividend;
        long d = divisor;
        
        n = abs(n);
        d = abs(d);
        int ans = 0;

        while(n >= d) {
            int count = 0;
            while(n >= (d << (count+1))) {
                count++;
            }
            
            // Updating the answer & dividend
            ans += (1 << count);
            n -= (d << count);
        }
        
        // Handling overflowing condition
        if(ans == (1 << 31) && isPositive) 
            return INT_MAX;
        if(ans == (1 << 31) && !isPositive)
            return INT_MIN;
        
        /* Returning the quotient 
        with proper sign */
        return isPositive ? ans : -1*ans;
    }
};