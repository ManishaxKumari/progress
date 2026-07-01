class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void solve(vector<int>& candidates,int idx,int target){
        if(target==0) {
            ans.push_back(v);
            return;
        }
        if(target<0) return;
        for(int i=idx; i <candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;

            v.push_back(candidates[i]);
            solve(candidates,i+1,target-candidates[i]);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,target);
        return ans;
    }
};