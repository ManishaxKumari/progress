class Solution {
private:
    void dfs(vector<int> &vis,vector<vector<int>> &adj,int node){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
               dfs(vis,adj,it);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //convert adj matrix into adj list
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    //adj[j].push_back(i);
                }
            }
        }

        //create visited array
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(vis,adj,i);
            }
        }
        return cnt;
    }
};