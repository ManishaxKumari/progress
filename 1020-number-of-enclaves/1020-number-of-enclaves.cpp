class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool valid(int &i,int &j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n ;
    }
    void dfs(int r,int c,vector<vector<int>> &ans ){
        int m=ans.size();
        int n=ans[0].size();
        ans[r][c]=0;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(valid(nr,nc,m,n) && ans[nr][nc]==1){
                dfs(nr,nc,ans);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans=grid;
        //remove boundary connected land
        for(int i=0;i<m;i++){
            if(ans[i][0]==1) dfs(i,0,ans);
            if(ans[i][n-1]==1) dfs(i,n-1,ans);
        }
        for(int j=0;j<n;j++){
            if(ans[0][j]==1) dfs(0,j,ans);
            if(ans[m-1][j]==1) dfs(m-1,j,ans);
        }

        //cnt remaining land
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==1) cnt++;
            }
        }
        return cnt;
        
    }
};