class Solution {
public:
    void func(vector<int>& nums,int index,int n,vector<vector<int>> &ans,vector<int> &arr){
        if(index==n){
            ans.push_back(arr);
            return;
        }
        //take
        arr.push_back(nums[index]);
        func(nums,index+1,n,ans,arr);
        //backtrack
        arr.pop_back();
        //not take
        func(nums,index+1,n,ans,arr);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>arr;
        int n=nums.size();
        func(nums,0,n,ans,arr);
        return ans;
    }
};