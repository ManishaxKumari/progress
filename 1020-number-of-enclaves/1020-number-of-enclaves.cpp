class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool valid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n ;
    }
    void dfs(int r,int c,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=r+dc[i];
            if(valid(nr,nc,m,n) && grid[nr][nc]==1){
                dfs(nr,nc,grid);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size(); // for looping we have to find m x n
        //loop for find all boundary touch lands and start dfs from it 
        for(int i=0;i<m;i++){
            if(grid[i][0] ==1) dfs(i,0,grid);
            if(grid[i][n-1] ==1) dfs(i,n-1,grid);
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1) dfs(0,j,grid);
            if(grid[m-1][j]==1) dfs(m-1,j,grid);
        }
        //enclosed land count
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
        

    }
};