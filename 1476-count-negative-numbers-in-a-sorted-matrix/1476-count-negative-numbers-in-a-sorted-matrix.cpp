class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int cnt=0;
        int row=0; // top left
        int col=cols-1; //top-right corner
        while(row<rows && col>=0){
            if(grid[row][col] <0 ){
                cnt+=(rows-row);
                col--; // move left
            }
            else{
                row++;
            }
        }
        return cnt;
    }
};