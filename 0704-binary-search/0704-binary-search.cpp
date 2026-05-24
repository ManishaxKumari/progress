class Solution {
public:
    int bs(int low,int high,vector<int>& nums,int target){
        if(low>high) return -1;
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target){
            return bs(low,mid-1,nums,target);
        }
        return bs(mid+1,high,nums,target);

    }
    int search(vector<int>& nums, int target) {
        return bs(0,nums.size()-1,nums,target);
    }
};