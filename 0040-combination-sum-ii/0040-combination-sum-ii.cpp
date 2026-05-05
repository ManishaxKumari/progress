class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>> &ans,vector<int>&v,int sum,int index){
        //base case
        if(sum==0){
            ans.push_back(v);
            return;
        }
        if(sum < 0 || index == candidates.size()) return; 
        v.push_back(candidates[index]);
        solve(candidates,ans,v,sum-candidates[index],index+1); 
        v.pop_back(); 

        for(int i = index + 1; i < candidates.size(); i++) {
            if(candidates[i] != candidates[index]) {
                solve(candidates,ans,v,sum,i); 
                break; 
            }
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