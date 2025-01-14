class Solution {
public:
    vector<int> pascal(vector<int> ans,int i){
        int n=i+2;
        vector<int> sub(n);
        sub[0]=1;
        sub[n-1]=1;
        int p=0;
        int q=1;
        for(int i=1;i<n-1;i++){
            sub[i]=(ans[p]+ans[q]);
            p++;
            q++;
        }
        return sub;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows>1){
            ans.push_back({1,1});
        }
        
        for(int i=1;i<numRows-1;i++){
            ans.push_back(pascal(ans[i],i));
        }
        return ans;
    }
};