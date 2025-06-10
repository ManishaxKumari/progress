class Solution {
public:
    bool isPowerOfTwo(int n) {
        //edge case 
        if(n<=0) return false;
        if(n==1) return true;
        return (n%2 == 0 && isPowerOfTwo(n/2));
    }
};