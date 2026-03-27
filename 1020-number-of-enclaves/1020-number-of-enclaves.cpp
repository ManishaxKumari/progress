class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool valid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n ;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans=grid;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
           if(ans[i][0]==1){
                q.push({i,0});
                ans[i][0] = 0;
            }
            if(ans[i][n-1]==1){
                q.push({i,n-1});
                ans[i][n-1]=0;
            }
        }
        for(int j=0;j<n;j++){
            if(ans[0][j]==1){
                q.push({0,j});
                ans[0][j]=0;
            }
            if(ans[m-1][j]==1){
                q.push({m-1,j});
                ans[m-1][j]=0;
            }
        }
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(valid(nr,nc,m,n) && ans[nr][nc]==1){
                    ans[nr][nc]=0;
                    q.push({nr,nc});
                }
        }
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