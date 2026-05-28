class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return true;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[mid]){ // left part sorted
                if(nums[low]<=target && target <=nums[mid]){ //element present in left sorted part
                    high=mid-1; // go to the left side
                }
                else low=mid+1;
            }
            else { //right part is sorted
                if(nums[mid]<=target && target <=nums[high]){ // element present in right part
                    low=mid+1; //go to the right part;
                }
                else high=mid-1;
            }
        }
        return false;
    }
};