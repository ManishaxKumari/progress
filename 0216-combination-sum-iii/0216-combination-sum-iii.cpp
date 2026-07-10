class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void solve(int k, int n,int idx){
        if(n==0 && k==0){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<=9;i++){
            if(k>0 && i<=n){
                v.push_back(i);
                solve(k-1,n-i,i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k,n,1);
        return ans;
    }
};