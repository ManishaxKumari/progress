class Solution {
public:
    void solve(int k , int n , vector<vector<int>> &result,vector<int> &path,int index){
        //store valid path
        if(k==0 && n==0){
            result.push_back(path);
        }
        // remove invalid path
        if(k==0 || n<0) return;

        for(int i=index; i<=9;i++){
            path.push_back(i);
            solve(k-1,n-i,result,path,i+1);
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>path;
        solve(k,n,result,path,1);
        return result;
    }
};