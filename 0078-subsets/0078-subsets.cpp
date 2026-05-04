class Solution {
public:
    void solve(vector<int>& nums,vector<int>&v,vector<vector<int>> &ans,int index){
        if(index>=nums.size()){
            ans.push_back(v);
            return;
        }
        //pick
        v.push_back(nums[index]);
        solve(nums,v,ans,index+1);
        //backtrack
        v.pop_back();
        //not pick
        solve(nums,v,ans,index+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>v;
        solve(nums,v,ans,0);
        return ans;
    }
};