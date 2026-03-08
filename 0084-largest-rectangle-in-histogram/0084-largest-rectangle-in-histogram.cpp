class Solution {
public:
    vector<int>findnse(vector<int>& arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int currele=arr[i];
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=!st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;

    }
    vector<int> findpse(vector<int>& arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            int currele=arr[i];
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=!st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse=findnse(heights);
        vector<int>pse=findpse(heights);
        int maxarea=0;
        int area;
        for(int i=0;i<n;i++){
            area=heights[i]*(nse[i]-pse[i]-1);
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};