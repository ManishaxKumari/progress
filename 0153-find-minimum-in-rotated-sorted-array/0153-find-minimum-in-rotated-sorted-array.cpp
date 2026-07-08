class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){ //you are in unsorted part
                low=mid+1;
            }
            else{ // you are in sorted part - stay
                high=mid;
            }
        }
        return nums[high];
    }
};