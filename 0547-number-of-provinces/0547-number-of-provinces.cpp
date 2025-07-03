class Solution {
private:
    void dfs(vector<int> &vis,vector<vector<int>> &isConnected,int node,int n){
        vis[node]=1;
        for(int j=0;j<n;j++){
            if(!vis[j] && isConnected[node][j]==1 ){
               dfs(vis,isConnected,j,n);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //create visited array
        int n= isConnected.size();
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(vis,isConnected,i,n);
            }
        }
        return cnt;
    }
};