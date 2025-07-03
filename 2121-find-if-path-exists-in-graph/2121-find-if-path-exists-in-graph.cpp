class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // mistake-> n is no. of nodes and in loop we write total number of realtions
        //convert relation into adj list
        vector<vector<int>> adj(n); // here use n
        for(int i=0;i<edges.size();i++){ // here use edge size = total connection
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
        }

        //create visited array
        vector<int> vis(n,0);
        queue<int> q;
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            int node=q.front();
            vis[node]=1;
            q.pop();
            if(node==destination) return true;
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return false;
    }
};