class Solution {
public:
    //space optimization
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum % 2)!=0) return false;
        int target=(sum/2);
        vector<int>prev(target+1,0);
        prev[0]=1;
        if(nums[0]<=target){
            prev[nums[0]]=1;
        }
        for(int i=1;i<n;i++){
            vector<int>temp(target+1,0);
            temp[0]=1;
            for(int j=1;j<=target;j++){
                int notake=prev[j];
                int take=0;
                if(nums[i]<=j){
                    take=prev[j-nums[i]];
                }
                temp[j]=take || notake;
            }
            prev=temp;
        }
        return prev[target];
    }
};