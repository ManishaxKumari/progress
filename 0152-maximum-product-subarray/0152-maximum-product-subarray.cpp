class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxproduct=INT_MIN;
        int prefix=1;
        int surfix=1;
        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(surfix==0) surfix=1;
            prefix*=nums[i];
            surfix*=nums[n-i-1];
            maxproduct=max(maxproduct,max(prefix,surfix));
        }
        return maxproduct;
    }
};