class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool isvalid(int i,int j , int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }

    void dfs( int r,int c,vector<vector<int>>& grid ,int m,int n){
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(isvalid(nr,nc,m,n)&& grid[nr][nc]==1){
                dfs(nr,nc,grid,m,n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]==1) dfs(i,0,grid,m,n);
            if(grid[i][n-1]==1) dfs(i,n-1,grid,m,n);
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1) dfs(0,j,grid,m,n);
            if(grid[m-1][j]==1) dfs(m-1,j,grid,m,n);
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;

    }
};