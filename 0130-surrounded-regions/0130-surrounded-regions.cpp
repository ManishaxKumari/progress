class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool isvalid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>> &vis,int m,int n){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(isvalid(nr,nc,m,n) && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr,nc,board,vis,m,n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(i,0,board,vis,m,n);
            if(board[i][n-1]=='O')  dfs(i,n-1,board,vis,m,n);
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O') dfs(0,j,board,vis,m,n);
            if(board[m-1][j]=='O')  dfs(m-1,j,board,vis,m,n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

    }
};