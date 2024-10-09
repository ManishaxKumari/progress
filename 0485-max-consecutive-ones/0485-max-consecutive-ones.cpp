class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int maxones=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) cnt++, maxones=max(cnt,maxones);
            if(nums[i]==0) cnt=0;
        }
        return maxones;
    }
};