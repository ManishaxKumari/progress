class Solution {
public:
    bool valid(int &i,int &j,int n,int m){
        if(i<0 || i >=n) return false;
        if(j<0 || j>=m) return false;
        return true;
    }
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    void dfs(int row,int col,int color,int inicol,vector<vector<int>> &ans){
        ans[row][col]=color;
        int n=ans.size();
        int m=ans[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(valid(nrow,ncol,n,m) && ans[nrow][ncol]==inicol){
                dfs(nrow,ncol,color,inicol,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int inicol=image[sr][sc];
        vector<vector<int>> ans=image;
        dfs(sr,sc,color,inicol,ans);
        return ans;
    }
};