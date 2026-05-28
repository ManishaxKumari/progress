class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=(low+high)/2;
            if(mid%2==1) mid--; // make mid even index
            if(nums[mid]==nums[mid+1]){ // normal side
                low=mid+2; // go ahead
            }
            else { //disruption side
                high=mid;
            }

        }
        return nums[low];

    }
};