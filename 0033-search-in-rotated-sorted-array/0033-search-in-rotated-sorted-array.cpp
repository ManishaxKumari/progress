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
            else if(nums[low]<=nums[mid]){ // if left part is sorted and right unsorted
                if(nums[low]<=target && target <=nums[mid]){ // ele present in sorted part->left
                    high=mid-1;
                }
                else{// ele present in sorted part->right
                    low=mid+1;
                }
            }
            else{// is right part is sorted and left unsorted
                if(nums[mid]<=target && target<=nums[high]){ // le present in sorted part->right
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