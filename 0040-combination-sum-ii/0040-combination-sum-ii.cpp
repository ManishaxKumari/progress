class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int>v,int idx){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0 || idx>=candidates.size()) return;

        v.push_back(candidates[idx]);
        solve(candidates,target-candidates[idx],ans,v,idx+1);
        v.pop_back();
        int next=idx+1;
        while(next<candidates.size() && candidates[idx]==candidates[next]) next++;
        solve(candidates,target,ans,v,next);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>v;
        solve(candidates,target,ans,v,0);
        return ans;
    }
};