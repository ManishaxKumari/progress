class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        
        for(int i=0;i<n-1;i++){
            int max=*max_element(arr.begin()+i+1, arr.end());
            swap(arr[i],max);
        }
        arr[n-1]=-1;
        return arr;
    }
};