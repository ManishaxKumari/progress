class Solution {
public:
    using t=tuple<int,int,int>;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool isvalid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<t,vector<t>,greater<t>> pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [diff,r,c]=pq.top();
            pq.pop();
            if(r==n-1 && c==m-1) return diff;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(isvalid(nr,nc,n,m)){
                    int maxdiff=max(diff,abs(heights[nr][nc]-heights[r][c]));
                    if(dist[nr][nc]>maxdiff){
                        dist[nr][nc]=maxdiff;
                        pq.push({maxdiff,nr,nc});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};