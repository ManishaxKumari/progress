class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //step1-> convert relation list into adj list
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,INT_MAX);
        queue<tuple<int,int,int>>q;
        q.push({0,src,0});
        dist[src]=0;

        while(!q.empty()){
            auto [stop,node,cost]=q.front();
            q.pop();
            if(stop>k) continue;
            for(auto &it : adj[node]){
                auto [adjNode,weight]=it;
                if(cost+weight <dist[adjNode] && stop<=k){
                    dist[adjNode]=cost+weight;
                    q.push({stop+1,adjNode,cost+weight});

                }
            }
        }

        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};