class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        if(nums[low]<nums[high]){
            return nums[low];
        }
        if(n==1) return nums[low];
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            //problematic check or duplication
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                ans=min(ans,nums[mid]);
                low++;
                high--;
                continue;
            }
            else if(nums[low]<=nums[mid]){ // if left part is sorted->store min-> eliminated
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