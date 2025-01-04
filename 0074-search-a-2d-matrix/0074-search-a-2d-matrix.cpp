class Solution {
public:
    bool findtarget(vector<int> arr,int target , int m){
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                return true;
            }
            if(target>arr[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(target>=matrix[i][0] && target <=matrix[i][m-1]){
                 return findtarget(matrix[i],target,m);
            }
         
        }
        return false;
    }
};