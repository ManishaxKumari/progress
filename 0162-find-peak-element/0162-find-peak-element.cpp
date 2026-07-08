class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int n=nums.size();
       int low=0;
       int high=n-1;
       while(low<high){
        int mid=low+(high-low)/2;
        if(nums[mid]>nums[mid+1]){ // may be mid is my ans - dont discard
            high=mid;
        }
        else low=mid+1;  // i am sure this is not my ans;
       }
       return high;
    }
};