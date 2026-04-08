class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();

        vector<int>leftsum(n);
        vector<int>rightsum(n);
        vector<int>ans(n);

        leftsum[0]=nums[0];
        rightsum[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            //prefixsum
            leftsum[i]=leftsum[i-1]+nums[i];
            //suffixsum
            rightsum[n-i-1]=rightsum[n-i]+nums[n-i-1];
        }
        for(int i=0;i<n;i++){
            ans[i]=abs(leftsum[i]-rightsum[i]);
        }
        return ans;

    }
};