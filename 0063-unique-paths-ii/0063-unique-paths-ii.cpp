class Solution {
public:
//space optimization
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n=Grid.size();
        int m=Grid[0].size();
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=0;j<m;j++){
                if(Grid[i][j]==1){
                    temp[j]=0;
                    continue;
                } 
                if(i==0 && j==0){
                    temp[j]=1;
                    continue;
                }

                int up=0;
                int left=0;
                if(i>0){
                    up=prev[j];
                }
                if(j>0){
                    left=temp[j-1];
                }
                temp[j]=left+up;

            }
            prev=temp;
        }
        return prev[m-1];
    }
};


