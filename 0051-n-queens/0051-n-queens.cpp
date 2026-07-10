class Solution {
public:
    bool issafe(int row,int col,vector<string> &board){
        int r=row;
        int c=col;
        //top
        while(r>=0){
            if(board[r][c]=='Q') return false;
            r--;
        }
        r=row;
        c=col;
        //upper right dia
        while(r>=0 && c<board.size()){
            if(board[r][c]=='Q') return false;
            r--;
            c++;         
        }
        r=row;
        c=col;
        //upper left dia
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;          
        }
        return true;
    }
    void solve(vector<vector<string>> &ans,vector<string> &board,int row){
        if(row==board.size()){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<board.size();col++){
            if(issafe(row,col,board)){
                board[row][col]='Q';
                solve(ans,board,row+1);
                board[row][col]='.';
            }
        }
    }   
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n,string(n,'.'));
        solve(ans,board,0);
        return ans;
    }
};