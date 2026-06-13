class DisjointSet {
public:
    vector<int>rank,parent,size;
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){ 
            parent[i]=i;
        }
    }
    int findHighestParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findHighestParent(parent[node]);
    }
    bool find(int u, int v) {
        return (findHighestParent(u)==findHighestParent(v));
    }

    void unionByRank(int u, int v) {
        int parentofU=findHighestParent(u);
        int parentofV=findHighestParent(v);
        if(parentofU==parentofV) return;
        if(rank[parentofU]>rank[parentofV]){
            parent[parentofV]= parentofU;
        }
        else if(rank[parentofU]<rank[parentofV]){
            parent[parentofU]= parentofV;
        }
        else{
            parent[parentofU]= parentofV;
            rank[parentofV]++;
        }
    }

    void unionBySize(int u, int v) {
        int parentofU=findHighestParent(u);
        int parentofV=findHighestParent(v);
        if(parentofU==parentofV) return;
        if(size[parentofU]>size[parentofV]){
            parent[parentofV]= parentofU;
            size[parentofU]+=size[parentofV];
        }
        else{
            parent[parentofU]= parentofV;
            size[parentofV]+=size[parentofU];
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalEdges=connections.size();
        if(totalEdges<n-1) return -1;
        DisjointSet ds(n);
        for(int i=0;i<totalEdges;i++){
            ds.unionByRank(connections[i][0],connections[i][1]);
        }

        int count=0; //total connected component
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) count++;
        }

        return count-1; //requirededges=connected componenet -1;

    }
};