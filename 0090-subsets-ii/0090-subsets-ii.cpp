class Solution {
private:
    void func(vector<int>& nums, vector<vector<int>> &ans, vector<int> v,int n,int ind){
        if(ind==n){
            ans.push_back(v);
            return;
        }
        //take it
        v.push_back(nums[ind]);
        func(nums,ans,v,n,ind+1);
        v.pop_back();
        //not take
        for(int i=ind+1;i<n;i++){
            if(nums[i]!=nums[ind]){
                func(nums,ans,v,n,i);
                return;
            }
        }
        // Ensure the function finishes when no more unique elements are left
       func(nums,ans,v,n,n);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        func(nums,ans,v,nums.size(),0);
        return ans;
    }
};