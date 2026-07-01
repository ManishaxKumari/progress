class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void solve(vector<int>& nums,vector<int> &visit){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visit[i]==1) continue;
            if(i>0 && visit[i-1]==1 &&  nums[i]==nums[i-1]) continue;

            visit[i]=1; 
            v.push_back(nums[i]);
            solve(nums,visit);
            v.pop_back();
            visit[i]=0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>visit(n,0);
        solve(nums,visit);
        return ans;
    }
};