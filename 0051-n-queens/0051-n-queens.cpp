class Solution {
public:
     bool safe(vector<string>& board, int row, int col) {
        int r = row, c = col;
         // Check upper left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }
        r = row;
        c = col;
         // Check upper side
        while (r >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
        }
        r = row;
        c = col;
        // Check upper right diagonal
        while (c < board.size() && r >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c++;
        }
        return true;
    }

    void func(int row,vector<string> &board,vector<vector<string>> &ans,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(safe(board,row,col)){
                board[row][col]='Q';
                func(row+1,board,ans,n);
                board[row][col]='.';
            }
        }
    } 
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s="";
        for(int i=0;i<n;i++){
            s=s+'.';
        }
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        func(0,board,ans,n);
        return ans;
    }
};