class Solution {
public:
    void dfs(int u,vector<int> &vis,vector<vector<int>>& isConnected,int n){
        vis[u]=1;
        for(int v=0;v<n;v++){
            if(!vis[v] && isConnected[u][v]==1){
                dfs(v,vis,isConnected,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(); // total no. of nodes
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,isConnected,n);
            }
        }
        return cnt;
    }
};