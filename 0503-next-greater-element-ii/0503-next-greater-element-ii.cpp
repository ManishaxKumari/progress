class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        stack<int>st;
        int n=arr.size();
        vector<int>ans(n);
        for(int i=2*(n-1);i>=0;i--){
            int ind=i%n;
            int x=arr[ind];
            while(!st.empty() && st.top()<=x ){
                    st.pop();
            }
            if(st.empty()){
                ans[ind]=-1;
            }
            else{
                ans[ind]=st.top();
            }
            st.push(x);

        }
        return ans;
    }
};