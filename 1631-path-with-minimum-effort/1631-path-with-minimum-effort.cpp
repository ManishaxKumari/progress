class Solution {
public:
    using t=tuple<int,int,int>;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool valid(int i,int j,int  m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<t,vector<t>,greater<t>>pq;
        vector<vector<int>>res(m,vector<int>(n,INT_MAX));
        pq.push({0,0,0});
        res[0][0]=0;
        while(!pq.empty()){
            auto [diff,r,c]=pq.top();
            pq.pop();
            if(r==m-1 && c==n-1) return diff;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(valid(nr,nc,m,n)){
                    int maxdiff=max(diff,abs(heights[nr][nc]-heights[r][c]));
                    if(res[nr][nc]>maxdiff){
                        res[nr][nc]=maxdiff;
                        pq.push({maxdiff,nr,nc});
                    }
            
                }
            }
        }
        return res[m-1][n-1];
    }
};