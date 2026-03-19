class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    bool valid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        // boundary
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(board[i][n-1]=='O'){
                q.push({i,n-1});
                vis[i][n-1]=1;
            }
        }

        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                vis[0][j]=1;
            }
            if(board[m-1][j]=='O'){
                q.push({m-1,j});
                vis[m-1][j]=1;
            }
        }

        // BFS
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(valid(nr, nc, m, n) && board[nr][nc]=='O' && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }

        // convert
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};