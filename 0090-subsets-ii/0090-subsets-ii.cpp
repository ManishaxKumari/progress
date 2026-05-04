class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> &v,int index){
        if(index==nums.size()){
            ans.push_back(v);
            return;
        }
        //pick
        v.push_back(nums[index]);
        solve(nums,ans,v,index+1);
        //backtrack
        v.pop_back();
        
        //not pick
        for(int i=index+1; i<nums.size();i++){
            if(nums[i]!=nums[index]){
                solve(nums,ans,v,i);
                return;
            }
        }
        //in case -> there is all same element ( no different element left)
        solve(nums,ans,v,nums.size());
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        solve(nums,ans,v,0);
        return ans;
    }
};