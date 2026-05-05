class Solution {
public:
    void solve(int n,int k,vector<vector<int>> &ans,vector<int> &v,int index){
        if(k==0){
            ans.push_back(v);
            return;
        }
        for(int i=index; i<=n;i++){
            v.push_back(i);     
            solve(n,k-1,ans,v,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(n,k,ans,v,1);
        return ans;
    }
};