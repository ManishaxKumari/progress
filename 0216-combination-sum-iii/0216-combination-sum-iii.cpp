class Solution {
public:
    vector<vector<int>> ans;
    vector<int>v;
    void solve(int k,int n,int idx){
        if(k==0 && n==0){
            ans.push_back(v);
            return;
        }
        if(n<0 || k<0) return;
        for(int i=idx;i<=9;i++){
            v.push_back(i);
            solve(k-1,n-i,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k,n,1);
        return ans;
    }
};