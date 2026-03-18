class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool valid(int &i,int &j,int &m,int &n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>> h(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){ //water
                    h[i][j]=0; //mark height
                    q.push({i,j}); //push all source
                }
            }
        }

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
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