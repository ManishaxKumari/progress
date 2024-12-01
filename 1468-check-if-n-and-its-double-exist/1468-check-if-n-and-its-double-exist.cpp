class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // int n=arr.size();
        // int temp[n];
        // for(int i=0;i<n;i++){
        //     temp[i]==arr[i]*2;
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(temp[i]==arr[j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        int n=arr.size();
        int i=0;
        int j=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i]==arr[j]*2 && i!=j){
                    return true;
                }
            }
        }
        return false;
        
    }
};