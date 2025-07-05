class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int more=target-nums[i];
            if(mpp.find(more)!=mpp.end()){
                ans.push_back(i+1);
                ans.push_back(mpp[more]+1);
                sort(ans.begin(),ans.end());
                return ans;
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};