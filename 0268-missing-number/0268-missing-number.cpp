class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int sum=((n+1)*n)/2;
        int arr_sum=accumulate(nums.begin(), nums.end(), 0);
        int missing_number=sum-arr_sum;
        return missing_number;
    }
};