class Solution {
public:
    bool check(vector<int>& nums , int mid){
        return nums[mid]<nums[mid+1];
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(nums,mid)){
                low=mid+1;
            }
            else high=mid;
        }
        return low;
    }
};