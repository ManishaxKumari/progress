class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int sum=0;
        while(l<r){
            sum=nums[l]+nums[r];
            if(sum==target){
                // +1 for 1-based indexing
                return {l+1,r+1};
            }
            else if(sum>target){
                //decrease kro
                r--;
            }
            else if(sum<target){
                //increase kro
                l++;
            }
        }
        return {-1,-1}; // if not found

    }
};