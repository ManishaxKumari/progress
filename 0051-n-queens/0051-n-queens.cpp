class Solution {
public:
    unordered_set<int>cols;
    unordered_set<int>Ldia;
    unordered_set<int>Rdia;
    void solve(int row,vector<vector<string>> &ans, vector<string>& board){
        if(row==board.size()){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<board[0].size();col++){
            int LeftDiaConst= row+col;
            int rightDiaConst=row-col;

            if(cols.find(col)!=cols.end() || Ldia.find(LeftDiaConst)!=Ldia.end()||Rdia.find(rightDiaConst)!=Rdia.end()) continue;

            cols.insert(col);
            Ldia.insert(LeftDiaConst);
            Rdia.insert(rightDiaConst);
            board[row][col]='Q';

            solve(row+1,ans,board);

            board[row][col]='.';
            cols.erase(col);
            Ldia.erase(LeftDiaConst);
            Rdia.erase(rightDiaConst);           

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string (n,'.'));

        solve(0,ans,board);
        return ans;

    }
};