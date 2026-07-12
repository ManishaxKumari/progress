class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool isvalid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int freshOrg=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshOrg++;
                }
            }
        }

        int time=0;
        while(!q.empty() && freshOrg>0 ){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(isvalid(nr,nc,m,n) && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        freshOrg--;
                        q.push({nr,nc});
                    }
                }
            }
            time++;
        }

        return freshOrg==0 ?  time : -1;

    }
};