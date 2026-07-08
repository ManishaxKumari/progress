class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[low]<=nums[mid]){ // left part sorted
                if(nums[low]<=target && target<=nums[mid]){ // exist in sorted part
                    high=mid-1;
                }
                else{ //exist in unsorted part
                    low=mid+1;
                }
            }
            else{//right part sorted
                if(nums[mid]<=target && target<=nums[high]){ //exist in sorted part
                    low=mid+1;
                }
                else{ //exist in unsorted part
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};