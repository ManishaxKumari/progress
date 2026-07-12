class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool isvalid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    void dfs(vector<vector<int>>& image, int r, int c, int color,int scolor,int m,int n){
        image[r][c]=color;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(isvalid(nr,nc,m,n) && image[nr][nc]==scolor){
                dfs(image,nr,nc,color,scolor,m,n);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int scolor=image[sr][sc];
        if(scolor==color) return image;
        dfs(image,sr,sc,color,scolor,m,n);
        return image;

    }
};