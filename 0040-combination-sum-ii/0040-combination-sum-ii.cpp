class Solution {
public:
        void func(vector<vector<int>> &ans,  vector<int> &v,vector<int>& arr, int sum,int i){
        if(sum==0){
            ans.push_back(v);
            return;
        }
        if(sum<0 || i==arr.size()){
            return;
        }
        //take
        v.push_back(arr[i]);
        func(ans,v,arr,sum-arr[i],i+1);
        v.pop_back();
        //not take and skip to different i 
        for(int j=i+1 ;j<arr.size();j++){
            if(arr[j] != arr[i]){
                func(ans,v,arr,sum,j);
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        func(ans,v,candidates,target,0);
        return ans;
    }
};