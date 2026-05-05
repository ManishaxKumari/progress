class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>> &ans,vector<int> &v,int sum,int index){
        //base case
        if(sum==0){
            ans.push_back(v);
            return;
        }
        if(index==candidates.size() || sum<0) return;

        //pick
        v.push_back(candidates[index]);
        solve(candidates,ans,v,sum-candidates[index],index);
        //notpick
        v.pop_back();
        solve(candidates,ans,v,sum,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>v;
        int sum=target;
        solve(candidates,ans,v,sum,0);
        return ans;
    }
};