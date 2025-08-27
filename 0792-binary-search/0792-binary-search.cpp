class Solution {
public:
    int search(vector<int>& nums, int x) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==x){
                return m;
            }
            else if(nums[m]<x){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return -1;
    }
};