class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int curr=nums[i];
            for(int j=1;j<n;j++){
                int index=(j+i)%n;
                if(nums[index]>curr){
                    ans[i]=nums[index];
                    break;
                }
            }
        }
        return ans;
    }
};