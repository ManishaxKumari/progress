class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> arr;
        long long ans=1;
        arr.push_back(1);
        for(int i=1;i<rowIndex+1;i++){
            ans=ans*(rowIndex+1-i);
            ans=ans/i;
            arr.push_back(ans);
        }
        return arr;
    }
};