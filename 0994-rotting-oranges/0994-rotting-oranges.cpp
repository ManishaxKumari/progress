class Solution {
public:
    bool valid(int &i,int &j,int m,int n){
        if(i<0 || i>=m) return false;
        if(j<0 || j>=n) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        //intialization
        int m=grid.size();
        int n=grid[0].size();
        int freshOrg=0;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshOrg++;
                }
            }
        }
        
        //direction
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int time=0;
        //bfs
        while(!q.empty() && freshOrg>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(valid(nr,nc,m,n) && !vis[nr][nc] && grid[nr][nc]==1){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                        freshOrg--;
                    }
                }
            }
            time++;
        }
        return freshOrg==0 ? time :-1;
    }
};