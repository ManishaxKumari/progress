class Solution {
public:
    void solve(vector<int>& nums,int sum,int &cnt,int &target,int index){
        //base case
        if(index==nums.size() && sum!=target) return;
        if(index==nums.size() && sum==target){
            cnt=cnt+1;
            return;
        }
        //pick plus
        solve(nums,sum+nums[index],cnt,target,index+1);
        //pick minus
        solve(nums,sum-nums[index],cnt,target,index+1);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int cnt=0;
        solve(nums,sum,cnt,target,0);
        return cnt;
    }
};