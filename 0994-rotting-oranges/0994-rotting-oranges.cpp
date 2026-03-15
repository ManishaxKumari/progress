class Solution {
public:

    bool valid(int i, int j, int n, int m){
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));

        int cntFresh = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }

                if(grid[i][j] == 1)
                    cntFresh++;
            }
        }

        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};

        int cnt = 0;
        int maxTime = 0;

        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            maxTime = max(maxTime, t);

            for(int i=0;i<4;i++){

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(valid(nr,nc,n,m) && vis[nr][nc] != 2 && grid[nr][nc] == 1){
                    q.push({{nr,nc}, t+1});
                    vis[nr][nc] = 2;
                    cnt++;
                }
            }
        }

        if(cnt != cntFresh) return -1;

        return maxTime;
    }
};