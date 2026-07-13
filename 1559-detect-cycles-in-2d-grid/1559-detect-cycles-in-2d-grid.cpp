class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool isvalid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    bool solve(vector<vector<char>>& grid,vector<vector<int>> &vis,int r,int c,int pr,int pc){
        int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(isvalid(nr,nc,m,n) && !vis[nr][nc] && grid[r][c]==grid[nr][nc]){
                if(solve(grid,vis,nr,nc,r,c)) return true;
            }
            else if(isvalid(nr,nc,m,n) && vis[nr][nc] && grid[r][c]==grid[nr][nc] && (pr!=nr  || pc!=nc)){
                return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(solve(grid,vis,i,j,i,j)) return true;
                }
            }
        }
        return false;
    }
};