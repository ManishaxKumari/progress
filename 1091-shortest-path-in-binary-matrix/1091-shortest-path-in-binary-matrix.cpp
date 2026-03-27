class Solution {
public:
    int dr[8]={-1,-1,-1,0,0,1,1,1};
    int dc[8]={-1,0,1,-1,1,-1,0,1};
    bool valid(int i,int j,int n){
        return i>=0 && j>=0 && i<n && j<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        //intialization
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(n,-1));
        q.push({0,0});
        dist[0][0]=1;
        //bfs
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(valid(nr,nc,n) && grid[nr][nc]==0 && dist[nr][nc]==-1){
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return dist[n-1][n-1];
    }
};