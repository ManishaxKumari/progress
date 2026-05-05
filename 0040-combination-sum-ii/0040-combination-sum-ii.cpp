class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>> &ans,vector<int>&v,int sum,int index){
        //base case
        if(sum==0){
            ans.push_back(v);
            return;
        }
        if(index==candidates.size() || sum<0) return;

        //pick
        v.push_back(candidates[index]);
        solve(candidates,ans,v,sum-candidates[index],index+1);
        v.pop_back();

        //skip duplicates
        while(index+1 < candidates.size() && candidates[index]==candidates[index+1]){
            index++;
        }
        //not pick
        solve(candidates,ans,v,sum,index+1);

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