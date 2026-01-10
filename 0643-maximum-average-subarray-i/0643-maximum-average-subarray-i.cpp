class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        long long windowsum=0;
        for(int i=0;i<k;i++){
            windowsum+=nums[i];
        }
        int l=0;
        int r=k-1;
        long long maxsum=windowsum;
        while(r<n-1){
            windowsum-=nums[l];
            l++;
            r++;
            windowsum+=nums[r];
            maxsum=max(maxsum,windowsum);
        }
        return (double)maxsum/k;
    }
};