class Solution {
public:
    vector<vector<int>> ans;
    vector<int>v;
    void solve(vector<int>& nums,int idx){
        ans.push_back(v);
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            solve(nums,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return ans;
    }
};