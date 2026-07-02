class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool solve(vector<vector<char>>& board, string &word,int r,int c,int idx,int m,int n){
        if(idx==word.size()) return true;
        if(r<0 || c<0 || r>=m || c>=n || board[r][c]=='$' || board[r][c]!=word[idx]){
            return false;
        }
        char temp=board[r][c];
        board[r][c]='$';
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(solve(board,word,nr,nc,idx+1,m,n)) return true;
        }
        board[r][c]=temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(board,word,i,j,0,m,n)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};