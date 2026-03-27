class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool valid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>>h(m,vector<int>(n,-1));
        //push all sources in queue and markes visited
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    h[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        //bfs
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                int nr=r+dr[j];
                int nc=c+dc[j];
                if(valid(nr,nc,m,n) && h[nr][nc]==-1){
                    h[nr][nc]=h[r][c]+1;
                    q.push({nr,nc});
                }
                }
            }

            
        }
        return h;

    }
};