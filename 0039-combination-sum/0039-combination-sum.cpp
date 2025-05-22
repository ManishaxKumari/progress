class Solution {
public:
     void func(vector<int>& arr,int i,int sum,vector<int> &v,vector<vector<int>> &ans){
        if(sum==0){
            ans.push_back(v);
            return;
        }
        if(sum<0 || i<0){
            return;
        }
        //not take
        func(arr,i-1,sum,v,ans);
        //take
        v.push_back(arr[i]);
        func(arr,i,sum-arr[i],v,ans);
        v.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;

        func(candidates,candidates.size()-1,target,v,ans);
        return ans;
    }
};