class Solution {
public:
    void func(vector<int>candidates, int target,int n,int idx,vector<vector<int>> &ans,vector<int> &arr){
        if(target<0 || idx>n) return;
        if(target==0){
            ans.push_back(arr);
            return;
        }

        arr.push_back(candidates[idx]);
        func(candidates,target-candidates[idx],n,idx,ans,arr);
        arr.pop_back();
        func(candidates,target,n,idx+1,ans,arr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>arr;
        func(candidates,target,candidates.size()-1,0,ans,arr);
        return ans;
    }
};