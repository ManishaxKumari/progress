class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            else if(nums[low]<=nums[mid]){ // ky left part sorted h??
                if(nums[low]<=target && target <=nums[mid]){ // target sorted part mai exist karta h?
                high=mid-1;
                }
                else { // unsorted part mai exist karta h
                    low=mid+1;
                }
            }
            else{ //right part sorted
                if(nums[mid]<=target && target <=nums[high]){
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