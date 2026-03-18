class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool valid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n ;
    }
    void dfs(vector<vector<int>> &ans,int r,int c){
        ans[r][c]=0; //visited
        int m=ans.size();
        int n=ans[0].size();
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(valid(nr,nc,m,n) && ans[nr][nc]==1){
                dfs(ans,nr,nc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans=grid;
        for(int i=0;i<m;i++){
            if(ans[i][0]==1) dfs(ans,i,0);
            if(ans[i][n-1]==1) dfs(ans,i,n-1);
        }
        for(int j=0;j<n;j++){
            if(ans[0][j]==1) dfs(ans,0,j);
            if(ans[m-1][j]==1) dfs(ans,m-1,j);
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;



    }
};