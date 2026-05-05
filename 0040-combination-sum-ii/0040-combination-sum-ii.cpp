class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>> &ans,vector<int>&v,int sum,int index){
        //base case
        if(sum==0){
            ans.push_back(v);
            return;
        }
        
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>sum) break;
            v.push_back(candidates[i]);
            solve(candidates,ans,v,sum-candidates[i],i+1);
            v.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        int sum=target;
        solve(candidates,ans,v,sum,0);
        return ans;
    }
};