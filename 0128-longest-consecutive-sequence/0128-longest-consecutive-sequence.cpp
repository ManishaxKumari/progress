class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int lastsmallest=INT_MIN;
        int cnt=0;
        int maxcnt=1;
        for(int i=0;i<n;i++){
            if(nums[i]== lastsmallest+1){
                cnt++;
                lastsmallest=nums[i];
            }
            else if(nums[i]!=lastsmallest){
                cnt=1;
                lastsmallest=nums[i];
            }
            maxcnt=max(cnt,maxcnt);
        }
        return maxcnt;
    }
};