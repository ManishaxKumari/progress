class disjoinSet{
public:
    vector<int>rank,size,parent;
    disjoinSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1); //mistake
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int ultimateparent(int node){
        if(node==parent[node]) return node;
        return parent[node]=ultimateparent(parent[node]);
    }
    bool find(int u,int v){
        return (ultimateparent(u) == ultimateparent(v));
    }

    void unionbyrank(int u,int v){
        int parent_u=ultimateparent(u);
        int parent_v=ultimateparent(v);
        if(parent_u==parent_v) return;
        if(rank[parent_u]>rank[parent_v]){
            parent[parent_v]=parent_u;
        }
        else if(rank[parent_u]<rank[parent_v]){
            parent[parent_u]=parent_v;
        }
        else{
            parent[parent_u]=parent_v;
            rank[parent_v]++;
        }

    }
    void unionbysize(int u,int v){ //mistake
        int parent_u=ultimateparent(u);
        int parent_v=ultimateparent(v);
        if(parent_u==parent_v) return;
        if(size[parent_u]>size[parent_v]){
            parent[parent_v]=parent_u;
            size[parent_u]+=size[parent_v];
        }
        else{
            parent[parent_u]=parent_v;
            size[parent_v]+=size[parent_u];
        }
    }
}; //mistake


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int NoOfEdges=connections.size();
        if(NoOfEdges<n-1) return -1;
        disjoinSet ds(n);
        for(auto i : connections ){
            ds.unionbyrank(i[0],i[1]);
        }
        //cnt total  number of component
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++; //mistake
        }

        return cnt-1;

    }
};