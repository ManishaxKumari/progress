class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool valid(int i,int j,int m,int n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    void dfs(int r,int c,int inicolor,int color,vector<vector<int>> &ans){
        int m=ans.size();
        int n=ans[0].size();
        ans[r][c]=color;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(valid(nr,nc,m,n) && ans[nr][nc]==inicolor){
                dfs(nr,nc,inicolor,color,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int m=image.size();
       int n=image[0].size();
       int inicolor=image[sr][sc];
       if(inicolor==color) return image;
       vector<vector<int>> ans=image;
       dfs(sr,sc,inicolor,color,ans);
        return ans;

    }
};