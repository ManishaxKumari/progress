class Solution {
public:
     bool func(vector<vector<char> >& b,int i,int j,string s,int k){
        if(k==s.size()){
            return true;
        }
        if(i<0 || j<0 || i>=b.size() ||j>=b[0].size() || s[k]!= b[i][j]){
            return false;
        }
        char x=b[i][j];
        b[i][j]=' ';

        bool ans=false;
        ans |= func(b, i + 1, j, s, k + 1);
        ans |= func(b, i - 1, j, s, k + 1);
        ans |= func(b, i, j + 1, s, k + 1);
        ans |= func(b, i, j - 1, s, k + 1);
        b[i][j] = x;
        
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board[0].size();
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    bool ans=func(board,i,j,word,0);
                    if(ans==true) return true;
                }
            }
        }
        return false;
    }
};