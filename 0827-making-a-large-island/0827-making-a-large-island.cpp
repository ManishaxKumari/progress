class disjointset{
public:
   vector<int>rank,size,parent;
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }

    int findUparent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUparent(parent[node]);
    }

    void unionbyrank(int u,int v){
        int parentofU=findUparent(u);
        int parentofV=findUparent(v);
        if(parentofU==parentofV) return;
        if(rank[parentofU]>rank[parentofV]){
            parent[parentofV]=parentofU;
        }
        else if(rank[parentofU]<rank[parentofV]){
            parent[parentofU]=parentofV;
        }
        else{
            parent[parentofU]=parentofV;
            rank[parentofV]++; 
        }
        return;
    }

    void unionbysize(int u, int v ){
        int parentofU=findUparent(u);
        int parentofV=findUparent(v);
        if(parentofU==parentofV) return;
         if(size[parentofU]>size[parentofV]){
            parent[parentofV]=parentofU;
            size[parentofU]+=size[parentofV];
        }
        else{
            parent[parentofU]=parentofV;
            size[parentofV]+=size[parentofU];
        }
        return;
    }
};


class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool isvalid(int i,int j,int n){
        return i>=0 && j>=0 && i<n && j<n;
    }

    void addintial(vector<vector<int>>& grid,int n, disjointset &ds){
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0) continue;
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(isvalid(nr,nc,n) && grid[nr][nc]==1){
                        int node=r*n + c;
                        int adjnode=nr*n+nc;

                        ds.unionbysize(node,adjnode);
                    }
                }
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disjointset ds(n*n);
        
        addintial(grid,n,ds);
        int ans=0;

        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1) continue;
                set<int> com;
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(isvalid(nr,nc,n) && grid[nr][nc]==1){
                        int node=nr*n+nc;
                        com.insert(ds.findUparent(node));
                    }
                }
                int totalsize=0;
                for(auto it : com){
                    totalsize+=ds.size[it];
                }

                ans=max(ans,totalsize+1);

            }
        }

        //edge case- what if their is not 0 only 1
        for(int i=0;i<n*n;i++){
            int uparent=ds.findUparent(i);
            ans=max(ans,ds.size[uparent]);
        }

        return ans;

    }
};