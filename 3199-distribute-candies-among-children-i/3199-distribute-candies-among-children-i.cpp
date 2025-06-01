class Solution {
public:
    int ans;
    void func(int n,int limit,int child){
        if(child==3){
            if(n==0){
                ans++;
            }
            return;
        }
        for(int i=0;i<=limit;i++){
            int give=i;
            func(n-give,limit,child+1);
        }
    }

    int distributeCandies(int n, int limit) {
        ans=0;
        func(n,limit,0);
        return ans;
    }
};