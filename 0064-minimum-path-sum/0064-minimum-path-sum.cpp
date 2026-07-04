class Solution {
public:
//space optimization 
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>prev(n,201);
        for(int i=0;i<m;i++){
            vector<int>temp(n,201);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j]=grid[0][0];
                    continue;
                }
                int up=INT_MAX;
                int left=INT_MAX;
                if(i>0){
                    up=prev[j];
                }
                if(j>0){
                    left=temp[j-1];
                }

                temp[j]=grid[i][j]+min(left,up);
            }
            prev=temp;
        }
        return prev[n-1];
    }
};