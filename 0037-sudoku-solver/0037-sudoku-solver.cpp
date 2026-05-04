class Solution {
public:
    bool isvalid(vector<vector<char>>& board,int row,int col,char d){
        for(int i=0;i<9;i++){
            if(board[i][col]==d) return false;
            if(board[row][i]==d) return false;
        }

        int start_i=row/3 * 3;
        int start_j=col/3 * 3;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(board[start_i + k][start_j + l]== d) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        //iterate over sudoku 9 x 9
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){ // if empty cell find -> fill it
                    for(char d='1'; d<='9';d++){ // you have 9 option choose which is valid and then explore
                    if(isvalid(board,i,j,d)){
                        board[i][j]=d;
                        if(solve(board)) return true;
                        board[i][j]='.';
                    }
                    }
                    //if you are not able to place any character then return false and undo
                    return false;
                }
                
            }
        }
        //if there is no empty cell
        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};