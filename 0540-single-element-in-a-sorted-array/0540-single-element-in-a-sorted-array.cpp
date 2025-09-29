class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        //edge cases
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        //trim search space
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            //if mid is single ele
            if(nums[mid] !=nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            // We are in the left part:
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1])
                || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                // Eliminate the left half:
                low = mid + 1;
            }
            // We are in the right part:
            else {
                // Eliminate the right half:
                high = mid - 1;
            }
        }
        return -1;


    }
};