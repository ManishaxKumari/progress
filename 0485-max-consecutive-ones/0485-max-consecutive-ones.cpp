class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int maxcnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
            }
            maxcnt=max(cnt,maxcnt);
            if(nums[i]==0){
                cnt=0;
            }
        }
        return maxcnt;
    }
};