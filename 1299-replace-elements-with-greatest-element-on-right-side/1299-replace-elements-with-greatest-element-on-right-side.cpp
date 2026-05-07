class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int currmax=-1;
        int nextmax=-1;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=currmax){
                nextmax=arr[i];
            }
            arr[i]=currmax;
            currmax=nextmax;
            
        }
        return arr;
    }
};