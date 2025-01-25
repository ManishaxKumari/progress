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
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            //which part is sorted
            if(nums[low]<=nums[mid]){//left sorted
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};