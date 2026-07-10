class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    bool solve(vector<vector<char>>& board, string word,int r,int c,int m,int n,int idx){
        if(idx>=word.size()){
            return true;
        }
        if(r<0 || c<0 || r>=m || c>=n || board[r][c]=='$' || board[r][c]!=word[idx] ) return false;
        char ch=board[r][c];
        board[r][c]='$';
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(solve(board,word,nr,nc,m,n,idx+1)) return true;
        }
        board[r][c]=ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(board,word,i,j,m,n,0)) return true;
                }
                
            }
        }
        return false;

    }
};