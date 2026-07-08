class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        if(nums[low]<nums[high]){
            return nums[low];
        }
        if(n==1) return nums[0];
        int mini=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[high]){ //right sorted part
                mini=min(mini,nums[mid]);
                high=mid-1;            
            }
            else{ //left part sorted
                mini=min(mini,nums[mid]);
                low=mid+1;
            }
        }
        return mini;
    }
};