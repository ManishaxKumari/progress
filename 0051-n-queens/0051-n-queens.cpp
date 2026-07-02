class Solution {
public:
    bool issafe(vector<string>& board,int row,int col){
        int r=row;
        int c=col;
        //check for top
        while(r>=0){
            if(board[r][c]=='Q') return false;
            r--;
        }
        r=row;
        c=col;
        //check for upper left diagonal
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        r=row;
        c=col;
        //check for upper right diagonal
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c++;
        }
        return true;
    }
    void solve(int row,vector<vector<string>> &ans, vector<string>& board){
        if(row==board.size()){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<board[0].size();col++){
            if(issafe(board,row,col)){
                board[row][col]='Q';
                solve(row+1,ans,board);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string (n,'.'));
        solve(0,ans,board);
        return ans;

    }
};