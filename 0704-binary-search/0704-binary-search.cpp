class Solution {
public:
    int bs(int low,int high,vector<int>& nums, int target){
        if(low>high) return -1;
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) {
            return bs(low,mid-1,nums,target);
        }
        return bs(mid+1,high,nums,target);
    }

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return bs(0,n-1,nums,target);
    }
};