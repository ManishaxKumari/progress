class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int index=0;
        int maxcnt=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                cnt+=mat[i][j];
                if(cnt>maxcnt){
                    maxcnt=cnt;
                    index=i;
                }

            }
        }
        return {index,maxcnt};
    }
};