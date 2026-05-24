class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int p=0;
        int q=n-1;
        while(p<=q){
            int mid=(p+q)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) q=mid-1;
            else p=mid+1;
        }
        return -1;
    }
};