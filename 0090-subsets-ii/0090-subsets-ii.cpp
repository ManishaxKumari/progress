class Solution {
public:
     void func(vector<int>& nums,int i,vector<int> &v,vector<vector<int>> &ans,int n){
        //base case
        if(i>=n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        func(nums,i+1,v,ans,n);
        v.pop_back();
        func(nums,i+1,v,ans,n);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>v;
        func(nums,0,v,ans,nums.size());
        set<vector<int>>ans2;
        vector<vector<int>>ans3;
        for(auto i:ans){
            sort(i.begin(),i.end());
            ans2.insert(i);
        }
        for(auto i : ans2){
            ans3.push_back(i);
        }
        return ans3;
    }
};