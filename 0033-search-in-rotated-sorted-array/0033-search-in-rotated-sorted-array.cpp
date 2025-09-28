class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[low]<=nums[mid]){ //check left side sorted or not
                if(nums[low]<=target && target <=nums[mid]){ // is ele present in sorted left part
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{ // right side sorted
                if(nums[mid]<=target && target<=nums[high]){//ele present in sorted part right side
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};