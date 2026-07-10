class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void solve(vector<int>& candidates, int target,int idx){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(idx<0 || target<0) return;
        v.push_back(candidates[idx]);
        solve(candidates,target-candidates[idx],idx);
        v.pop_back();
        solve(candidates,target,idx-1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates,target,candidates.size()-1);
        return ans;
    }
};