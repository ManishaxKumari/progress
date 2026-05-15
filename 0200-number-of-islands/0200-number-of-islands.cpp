class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool valid(int i,int j,int m,int n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    void dfs(vector<vector<char>>& grid,int r,int c){
        int m=grid.size();
        int n=grid[0].size();
        grid[r][c]='0';
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(valid(nr,nc,m,n) && grid[nr][nc]=='1'){
                dfs(grid,nr,nc);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};